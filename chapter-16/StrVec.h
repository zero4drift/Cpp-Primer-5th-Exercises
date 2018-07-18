#ifndef STRVEC_H
#define STRVEC_H


#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <exception>
#include <initializer_list>
#include <algorithm>

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

class StrVec
{
  friend bool operator==(const StrVec &, const StrVec &);
  friend bool operator!=(const StrVec &, const StrVec &);
  friend bool operator<(const StrVec &, const StrVec &);
 public:
 StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(const StrVec &);
  StrVec(StrVec &&) noexcept;
  StrVec(const initializer_list<string> &is);
  StrVec &operator=(const StrVec &);
  StrVec &operator=(StrVec &&) noexcept;
  StrVec &operator=(const initializer_list<string> &);
  string &operator[](size_t n);
  const string &operator[](size_t n) const;
  ~StrVec();
  void push_back(const string &);
  template <typename... Args> void emplace_back(Args&&...);
  size_t size() const {return first_free - elements;}
  size_t capacity() const {return cap - elements;}
  void reserve(size_t);
  void resize(size_t n, string s = "");
  string *begin() const {return elements;}
  string *end() const {return first_free;}
 private:
  allocator<string> alloc; /* it using static, 'undefined reference' reported when compile */
  void chk_n_alloc()
  {if(size() == capacity()) reallocate();}
  pair<string *, string *> alloc_n_copy
    (const string *, const string *);
  void free();
  void reallocate(size_t n = 0);
  string *elements;
  string *first_free;
  string *cap;
};


#endif
