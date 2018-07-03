#ifndef STRBLOB_H
#define STRBLOB_H


#include <vector>
#include <string>
#include <memory>
#include <exception>

using std::size_t;
using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using std::initializer_list;
using std::runtime_error;
using std::out_of_range;

class StrBlobPtr;

class StrBlob
{
  friend class StrBlobPtr;
  friend class ConstStrBlobPtr;
  friend bool operator==(const StrBlob &, const StrBlob &);
  friend bool operator!=(const StrBlob &, const StrBlob &);
  friend bool operator<(const StrBlob &, const StrBlob &);
 public:
  typedef vector<string>::size_type size_type;
  StrBlob();
  StrBlob(initializer_list<string> il);
  StrBlob(const StrBlob &);
  StrBlob &operator=(const StrBlob &);
  string &operator[](size_t n);
  const string &operator[](size_t n) const;
  size_type size() const {return data->size();}
  bool empty() const {return data->empty();}
  void push_back(const string &t) {data->push_back(t);}
  void push_back(string &&t) {data->push_back(std::move(t));}
  void pop_back();
  string &front();
  const string &front() const;
  string &back();
  const string &back() const;
  StrBlobPtr begin();
    StrBlobPtr end();
 private:
  shared_ptr<vector<string>> data;
  void check(size_type i, const string &msg) const;
};


class StrBlobPtr
{
  friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
  friend StrBlobPtr operator+(const StrBlobPtr &, size_t n);
  friend StrBlobPtr operator-(const StrBlobPtr &, size_t n);
 public:
  string &operator[](size_t n);
  const string &operator[](size_t n) const;
  StrBlobPtr &operator++();
  StrBlobPtr &operator--();
  StrBlobPtr operator++(int);
  StrBlobPtr operator--(int);
  string &operator*();
  string *operator->();
 StrBlobPtr(): curr(0) {}
 StrBlobPtr(StrBlob &a, size_t sz = 0):
  wptr(a.data), curr(sz) {}
  string &deref() const;
  StrBlobPtr &incr();
 private:
  shared_ptr<vector<string>> check(size_t,const string&) const;
  weak_ptr<vector<string>> wptr;
  size_t curr;
};


class ConstStrBlobPtr
{
 public:
 ConstStrBlobPtr(): curr(0) {}
 ConstStrBlobPtr(const StrBlob &a, size_t sz = 0):
  wptr(a.data), curr(sz) {}
  const string &deref() const;
  ConstStrBlobPtr &incr();
  const string &operator*();
  const string *operator->();
 private:
  shared_ptr<vector<string>> check(size_t,const string&) const;
  weak_ptr<vector<string>> wptr;
  size_t curr;
};


#endif
