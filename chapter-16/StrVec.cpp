#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <exception>
#include <initializer_list>
#include <algorithm>
#include "StrVec.h"

using std::vector;
using std::string;
using std::size_t;
using std::allocator;
using std::uninitialized_copy;
using std::uninitialized_fill;
using std::pair;
using std::runtime_error;
using std::initializer_list;
using std::for_each;

void StrVec::push_back(const string &s)
{
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

template <typename... Args>
inline
void StrVec::emplace_back(Args&&... args)
{
  chk_n_alloc();
  alloc.construct(first_free++, std::forward<Args>(args)...);
}

pair<string *, string *>
  StrVec::alloc_n_copy(const string *b, const string *e)
{
  auto data = alloc.allocate(e - b);
  return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
  if(elements)
    {
      for(auto p = first_free; p != elements;)
  	alloc.destroy(--p);
      alloc.deallocate(elements, cap - elements);
    }
  /* for_each(elements, first_free, [this] (string &s) {alloc.destroy(&s);}); */
  /* alloc.deallocate(elements, cap - elements); */
}

StrVec::StrVec(const StrVec &s)
{
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec &&s) noexcept: first_free(s.first_free), elements(s.elements), cap(s.cap)
{
  s.first_free = nullptr;
  s.elements = nullptr;
  s.cap = nullptr;
}

StrVec::StrVec(const initializer_list<string> &is)
{
  auto newdata = alloc_n_copy(is.begin(), is.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

StrVec::~StrVec() {free();}

StrVec &StrVec::operator=(const StrVec &rhs)
{
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

  string &StrVec::operator[](size_t n)
  {
    if(n >= size())
      throw runtime_error("Out of range");
    else
      return *(elements + n);
  }

const string &StrVec::operator[](size_t n) const
{
  if(n >= size())
    throw runtime_error("Out of range");
  else
    return elements[n];
}

StrVec &StrVec::operator=(StrVec &&s) noexcept
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

  StrVec &StrVec::operator=(const initializer_list<string> &il)
  {
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
  }
  
  void StrVec::reallocate(size_t n)
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

void StrVec::reserve(size_t n)
{
  if(n > capacity())
    reallocate(n);
}

void StrVec::resize(size_t n, string s)
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

bool operator==(const StrVec &s1, const StrVec &s2)
{
  vector<string> temp1(s1.begin(), s1.end());
  vector<string> temp2(s2.begin(), s2.end());
  return temp1 == temp2;
}

bool operator!=(const StrVec &s1, const StrVec &s2)
{
  return !(s1 == s2);
}

bool operator<(const StrVec &s1, const StrVec &s2)
{
  vector<string> temp1(s1.begin(), s1.end());
  vector<string> temp2(s2.begin(), s2.end());
  return temp1 < temp2;
}
