#ifndef VEC_H
#define VEC_H


#include <vector>
#include <memory>
#include <utility>
#include <exception>
#include <initializer_list>
#include <algorithm>

using std::vector;
using std::size_t;
using std::allocator;
using std::uninitialized_copy;
using std::uninitialized_fill;
using std::pair;
using std::runtime_error;
using std::initializer_list;
using std::for_each;

template <typename T> class Vec;

template <typename T> bool operator==(const Vec<T> &, const Vec<T> &);

template <typename T> bool operator!=(const Vec<T> &, const Vec<T> &);

template <typename T> bool operator<(const Vec<T> &, const Vec<T> &);

template <typename T> class Vec
{
  friend bool operator==<T>(const Vec<T> &, const Vec<T> &);
  friend bool operator!=<T>(const Vec<T> &, const Vec<T> &);
  friend bool operator< <T>(const Vec<T> &, const Vec<T> &);
 public:
 Vec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
  Vec(const Vec &);
  Vec(Vec &&) noexcept;
  Vec(const initializer_list<T> &is);
  Vec &operator=(const Vec &);
  Vec &operator=(Vec &&) noexcept;
  Vec &operator=(const initializer_list<T> &);
  T &operator[](size_t n);
  const T &operator[](size_t n) const;
  ~Vec();
  void push_back(const T &);
  template <typename... Args> void emplace_back(Args&&...);
  size_t size() const {return first_free - elements;}
  size_t capacity() const {return cap - elements;}
  void reserve(size_t);
  void resize(size_t n, T s = "");
  T *begin() const {return elements;}
  T *end() const {return first_free;}
 private:
  allocator<T> alloc; /* it using static, 'undefined reference' reported when compile */
  void chk_n_alloc()
  {if(size() == capacity()) reallocate();}
  pair<T *, T *> alloc_n_copy
    (const T *, const T *);
  void free();
  void reallocate(size_t n = 0);
  T *elements;
  T *first_free;
  T *cap;
};


template <typename T> void Vec<T>::push_back(const T &s)
{
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

template <typename T>
template <typename... Args>
inline
void Vec<T>::emplace_back(Args&&... args)
{
  chk_n_alloc();
  alloc.construct(first_free++, std::forward<Args>(args)...);
}

template <typename T> pair<T *, T *>
Vec<T>::alloc_n_copy(const T *b, const T *e)
{
  auto data = alloc.allocate(e - b);
  return {data, uninitialized_copy(b, e, data)};
}

template <typename T> void Vec<T>::free()
{
  if(elements)
    {
      for(auto p = first_free; p != elements;)
  	alloc.destroy(--p);
      alloc.deallocate(elements, cap - elements);
    }
  /* for_each(elements, first_free, [this] (T &s) {alloc.destroy(&s);}); */
  /* alloc.deallocate(elements, cap - elements); */
}

template<typename T> Vec<T>::Vec(const Vec &s)
{
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

template<typename T> Vec<T>::Vec(Vec &&s) noexcept: first_free(s.first_free), elements(s.elements), cap(s.cap)
{
  s.first_free = nullptr;
  s.elements = nullptr;
  s.cap = nullptr;
}

template<typename T> Vec<T>::Vec(const initializer_list<T> &is)
{
  auto newdata = alloc_n_copy(is.begin(), is.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

template<typename T> Vec<T>::~Vec() {free();}

template<typename T> Vec<T> &Vec<T>::operator=(const Vec &rhs)
{
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

template<typename T> T &Vec<T>::operator[](size_t n)
{
  if(n >= size())
    throw runtime_error("Out of range");
  else
    return *(elements + n);
}

template<typename T> const T &Vec<T>::operator[](size_t n) const
{
  if(n >= size())
    throw runtime_error("Out of range");
  else
    return elements[n];
}

template<typename T> Vec<T> &Vec<T>::operator=(Vec &&s) noexcept
{
  if(&s != this)
    {
      free();
      first_free = s.first_free;
      elements = s.elements;
      cap = s.cap;
      s.first_free = s.elements = s.cap = nullptr;
    }
  return *this;
}

template<typename T> Vec<T> &Vec<T>::operator=(const initializer_list<T> &il)
{
  auto data = alloc_n_copy(il.begin(), il.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

template<typename T> void Vec<T>::reallocate(size_t n)
{
  auto newcapacity = n ? n : (size() ? 2 * size() : 1);
  auto newdata = alloc.allocate(newcapacity);
  auto dest = newdata;
  auto elem = elements;
  for(size_t i = 0; i != size(); ++i)
    alloc.construct(dest++, std::move(*elem++));
  free();
  elements = newdata;
  first_free = dest;
  cap = elements + newcapacity;
}

template<typename T> void Vec<T>::reserve(size_t n)
{
  if(n > capacity())
    reallocate(n);
}

template<typename T> void Vec<T>::resize(size_t n, T s)
{
  if(n > size() && n <= capacity())
    {
      uninitialized_fill(first_free, elements + n, s);
      first_free = elements + n;
    }
  else if(n > size() && n > capacity())
    {
      reallocate();
      uninitialized_fill(first_free, elements + n, s);
      first_free = elements + n;
    }
  else if(n < size())
    {
      for(auto p = first_free; p != elements + n;)
	alloc.destroy(--p);
    }
}

template <typename T> bool operator==(const Vec<T> &s1, const Vec<T> &s2)
{
  vector<T> temp1(s1.begin(), s1.end());
  vector<T> temp2(s2.begin(), s2.end());
  return temp1 == temp2;
}

template <typename T> bool operator!=(const Vec<T> &s1, const Vec<T> &s2)
{
  return !(s1 == s2);
}

template <typename T> bool operator<(const Vec<T> &s1, const Vec<T> &s2)
{
  vector<T> temp1(s1.begin(), s1.end());
  vector<T> temp2(s2.begin(), s2.end());
  return temp1 < temp2;
}


#endif
