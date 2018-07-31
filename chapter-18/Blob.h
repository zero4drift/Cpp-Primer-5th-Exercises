#include <string>
#include <vector>
#include <memory>
#include <exception>
#include <typeinfo>
#include <cstdlib>
#include <iostream>
#include "My_shared_ptr.h"

using std::string;
using std::size_t;
using std::vector;
using std::weak_ptr;
using std::initializer_list;
using std::runtime_error;
using std::bad_alloc;
using std::abort;
using std::cerr;
using std::endl;
using std::out_of_range;

template <typename T> class BlobPtr;

template <typename T> class Blob
{
  friend class BlobPtr<T>;
 public:
  using sh = My_shared_ptr<vector<T>>;
  typedef typename vector<T>::size_type size_type;
  Blob();
  Blob(initializer_list<T> il);
  template <typename It> Blob(It it1, It it2);
  size_type size() const {return data->size();}
  bool empty() const {return data->empty();}
  void push_back(const T &t) {data->push_back(t);}
  void push_back(T &&t) {data->push_back(std::move(t));}
  void pop_back();
  T &front();
  const T &front() const;
  T &back();
  const T &back() const;
  T &operator[](size_type i);
  BlobPtr<T> begin();
  BlobPtr<T> end();
 private:
  sh data;
  void check(size_type i, const string &msg) const;
};

template <typename T> Blob<T>::Blob()
try: data(sh()) {}
catch(const bad_alloc &e) {cerr << e.what() << endl; abort();}

template <typename T> Blob<T>::Blob(initializer_list<T> il)
try: data(sh(il)) {}
catch(const bad_alloc &e) {cerr << e.what() << endl; abort();}

template <typename T>
template <typename It>
Blob<T>::Blob(It it1, It it2): data(sh(it1, it2)) {}

template <typename T> void Blob<T>::check(size_type i, const string &msg) const
{
  if(i >= data->size())
    throw out_of_range(msg);
}

template <typename T> T& Blob<T>::front()
{
  check(0, "front on empty Blob");
  return data->front();
}

template <typename T> const T &Blob<T>::front() const
{
  check(0, "front on empty Blob");
  return data->front();
}

template <typename T> T &Blob<T>::back()
{
  check(0, "badk on empty Blob");
  return data->back();
}

template <typename T> const T &Blob<T>::back() const
{
  check(0, "back on empty Blob");
  return data->back();
}

template <typename T> T &Blob<T>::operator[](size_type i)
{
  check(i, "subscript out of range");
  return (*data)[i];
}

template <typename T> bool operator==(const BlobPtr<T> &a, const BlobPtr<T> &b)
{
  if(a.wptr.lock() == b.wptr.lock())
    {
      throw runtime_error("ptrs to different Blobs!");
    }
  return a.curr == b.curr;
}

template <typename T> bool operator< (const BlobPtr<T> &a, const BlobPtr<T> &b)
{
  if(a.wptr.lock() != b.wptr.lock())
    {
      throw runtime_error("ptrs to different Blobs!");
    }
  return a.curr < b.curr;
}

template <typename T> class BlobPtr
{
  friend bool operator==<T>(const BlobPtr<T> &, const BlobPtr<T> &);
  friend bool operator< <T>
    (const BlobPtr<T> &, const BlobPtr<T> &);
 public:
 BlobPtr(): curr(0) {}
 BlobPtr(Blob<T> &a, size_t sz = 0): wptr(a.data), curr(sz) {}
  T &operator*() const
    {
      auto p = check(curr, "dereference past end");
      return (*p)[curr];
    }
  BlobPtr &operator++();
  BlobPtr &operator--();
 private:
  My_shared_ptr<vector<T>> check(size_t,const string&) const;
  weak_ptr<vector<T>> wptr;
  size_t curr;
};

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++()
{
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--()
{
  --curr;
  check(curr, "increment past end of StrBlobPtr");
  return *this;
}

template <typename T> My_shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string &msg) const
{
  auto ret = wptr.lock();
  if(!ret)
    throw runtime_error("unbound BlobPtr");
  if(i >= ret->size())
    throw out_of_range(msg);
  return ret;
}

