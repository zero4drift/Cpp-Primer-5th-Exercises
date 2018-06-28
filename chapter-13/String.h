#include <memory>
#include <utility>
#include <exception>
#include <cstring>
#include <iostream>

using std::size_t;
using std::allocator;
using std::uninitialized_copy;
using std::uninitialized_fill;
using std::pair;
using std::strlen;
using std::cout;
using std::endl;

class String
{
 public:
 String(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
  String(const char *);
  String(const String &);
  String &operator=(const String &);
  char &operator[](size_t n);
  ~String();
  void push_back(const char &);
  size_t size() const {return first_free - elements;}
  size_t capacity() const {return cap - elements;}
  char *begin() const {return elements;}
  char *end() const {return first_free;}
  void print();
 private:
  allocator<char> alloc; /* it using static, 'undefined reference' reported when compile */
  void chk_n_alloc()
  {if(size() == capacity()) reallocate();}
  pair<char *, char *> alloc_n_copy
    (const char *, const char *);
  void free();
  void reallocate(size_t n = 0);
  char *elements;
  char *first_free;
  char *cap;
};

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
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

String::~String()
{
  free();
}

String &String::operator=(const String &rhs)
{
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
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

void String::print()
{
  for(auto p = elements; p != first_free; ++p)
    cout << *p;
  cout << endl;
}