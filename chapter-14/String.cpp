#include <string>
#include <memory>
#include <utility>
#include <exception>
#include <cstring>
#include <iostream>
#include "String.h"

using std::string;
using std::size_t;
using std::allocator;
using std::uninitialized_copy;
using std::uninitialized_fill;
using std::runtime_error;
using std::pair;
using std::strlen;
using std::ostream;
using std::cout;
using std::endl;

void String::push_back(const char &s)
{
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

pair<char *, char *>
  String::alloc_n_copy(const char *b, const char *e)
{
  auto data = alloc.allocate(e - b);
  return {data, uninitialized_copy(b, e, data)};
}

void String::free()
{
  if(elements)
    {
      for(auto p = first_free; p != elements;)
  	alloc.destroy(--p);
      alloc.deallocate(elements, cap - elements);
    }
}

String::String(const char *c)
{
  auto length = strlen(c);
  auto newdata = alloc_n_copy(c, c + length);
  elements = newdata.first;
  first_free = cap = newdata.second;
}

String::String(const String &s)
{
  cout << "String::String(const String &s)" << endl;
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

String::String(String &&s) noexcept: first_free(s.first_free), elements(s.elements), cap(s.cap)
{
  cout << "String::String(String &&s)" << endl;
  s.first_free = nullptr;
  s.elements = nullptr;
  s.cap = nullptr;
}

String::~String()
{
  free();
}

char &String::operator[](size_t n)
{
  if(n >= size())
    throw runtime_error("out of range");
  else
    return elements[n];
}

const char &String::operator[](size_t n) const
{
  if(n >= size())
    throw runtime_error("out of range");
  else
    return elements[n];
}

String &String::operator=(const String &rhs)
{
  cout << "String &String::operator=(const String &rhs)" << endl;
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

  String &String::operator=(String &&s) noexcept
  {
    cout << "String &String::operator=(String &&s)" << endl;
    if(&s != this)
      {
	free();
	first_free = s.first_free;
	elements = s.elements;
	cap = s.cap;
      }
    return *this;
  }
  
    void String::reallocate(size_t n)
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

ostream &String::print()
{
  for(auto p = elements; p != first_free; ++p)
    cout << *p;
  return cout;
}

bool operator==(const String &s1, const String &s2)
{
  string temp1(s1.begin(), s1.end());
  string temp2(s2.begin(), s2.end());
  return temp1 == temp2;
  // clever but lower efficiency compared to standard answer
  // return (s1.size() == s2.size() && equal(s1.begin(), s1.end(), s2.begin()));
}

bool operator!=(const String &s1, const String &s2)
{
  return !(s1 == s2);
}

bool operator<(const String &s1, const String &s2)
{
  string temp1(s1.begin(), s1.end());
  string temp2(s2.begin(), s2.end());
  return temp1 < temp2;
}

ostream &operator<<(ostream &o, const String &s)
{
  for(auto p = s.elements; p != s.first_free; ++p)
    cout << *p;
  return cout;
}
