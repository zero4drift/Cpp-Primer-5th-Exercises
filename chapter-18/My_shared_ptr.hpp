#ifndef MY_SHARED_PTR_H
#define MY_SHARED_PTR_H


#include <functional>
#include <initializer_list>

using std::function;
using std::initializer_list;

template <typename T> class My_shared_ptr
{
 public:
  using del_type = function<void(T*)>;
 My_shared_ptr(): p(new T()), use_count(new unsigned(1)) {}
 My_shared_ptr(T *q): p(q), use_count(new unsigned(1)) {}
 My_shared_ptr(T *q, del_type d): p(q), del(d), use_count(new unsigned(1)) {}
 My_shared_ptr(const My_shared_ptr &m): p(m.p), del(m.del), use_count(m.use_count) {++*use_count;}
 My_shared_ptr(initializer_list<typename T::value_type> il): p(new T(il)), use_count(new unsigned(1)) {}
 My_shared_ptr(typename T::iterator it1, typename T::iterator it2):
  p(new T(it1, it2)), use_count(new unsigned(1)) {}
  My_shared_ptr &operator=(const My_shared_ptr &m);
  void reset();
  void reset(T *q);
  void reset(T *q, del_type d);
  T *operator->() const {return p;}
  T &operator*() const {return *p;}
  ~My_shared_ptr();
 private:
  T* p;
  unsigned *use_count;
  del_type del = [] (T *p) {delete p;};
};

template <typename T>
My_shared_ptr<T> &My_shared_ptr<T>::operator=(const My_shared_ptr &m)
{
  ++*m.use_count;
  if(--*use_count == 0)
    {
      del(p);
      delete use_count;
    }
  p = m.p;
  use_count = m.use_count;
  return *this;
}

  template<typename T> void My_shared_ptr<T>::reset()
  {
    if(--*use_count == 0) 
      del(p);
    p = nullptr;
    *use_count = 0;
  }

template<typename T> void My_shared_ptr<T>::reset(T *q)
{
  if(--*use_count == 0) 
    del(p);
  p = q;
  *use_count = 1;
}

template<typename T> void My_shared_ptr<T>::reset(T *q, del_type d)
{
  if(--*use_count == 0) 
    del(p);
  p = q;
  del = d;
  *use_count = 1;
}

template<typename T> My_shared_ptr<T>::~My_shared_ptr()
{
  if(--*use_count == 0)
    {
      del(p);
      delete use_count;
    }
}


#endif
