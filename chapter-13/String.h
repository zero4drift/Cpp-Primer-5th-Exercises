#ifndef STRING_H_EX
#define STRING_H_EX


#include <string>
#include <memory>
#include <utility>
#include <exception>
#include <cstring>
#include <iostream>

using std::string;
using std::size_t;
using std::allocator;
using std::uninitialized_copy;
using std::uninitialized_fill;
using std::pair;
using std::strlen;
using std::ostream;
using std::cout;
using std::endl;

class String
{
  friend bool operator==(const String &, const String &);
  friend bool operator!=(const String &, const String &);
  friend bool operator<(const String &, const String &);
 public:
 String(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
  String(const char *);
  String(const String &);
  String(String &&) noexcept;
  String &operator=(const String &);
  String &operator=(String &&) noexcept;
  char &operator[](size_t n);
  const char &operator[](size_t n) const;
  ~String();
  void push_back(const char &);
  size_t size() const {return first_free - elements;}
  size_t capacity() const {return cap - elements;}
  char *begin() const {return elements;}
  char *end() const {return first_free;}
  ostream &print();
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


#endif
