#include <vector>
#include <string>
#include <memory>
#include <exception>
#include "StrBlob.h"

using std::size_t;
using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using std::initializer_list;
using std::runtime_error;
using std::out_of_range;

// StrBlob member
StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il):
data(make_shared<vector<string>>(il)) {}
StrBlob::StrBlob(const StrBlob &s): data(make_shared<vector<string>>(*s.data)) {}

StrBlob &StrBlob::operator=(const StrBlob &s)
{
  data = make_shared<vector<string>>(*s.data);
  return *this;
}

string &StrBlob::operator[](size_t n)
{
  return (*data)[n];
}

const string &StrBlob::operator[](size_t n) const
{
  return (*data)[n];
}

void StrBlob::check(size_type i, const string &msg) const
{
  if(i >= data->size())
    throw out_of_range(msg);
}

string &StrBlob::front()
{
  check(0, "front on empty StrBlob");
  return data->front();
}

const string &StrBlob::front() const
{
  check(0, "front on empty StrBlob");
  return data->front();
}

string &StrBlob::back()
{
  check(0, "badk on empty StrBlob");
  return data->back();
}

const string &StrBlob::back() const
{
  check(0, "back on empty StrBlob");
  return data->back();
}

bool operator==(const StrBlob &s1, const StrBlob &s2)
{
  return *(s1.data) == *(s2.data);
}

bool operator!=(const StrBlob &s1, const StrBlob &s2)
{
  return !(s1 == s2);
}

bool operator<(const StrBlob &s1, const StrBlob &s2)
{
  return *(s1.data) < *(s2.data);
}


// StrBlobPtr member
shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
  auto ret = wptr.lock();
  if(!ret)
    throw runtime_error("unbound StrBlobPtr");
  if(i >= ret->size())
    throw out_of_range(msg);
  return ret;
}

string &StrBlobPtr::operator[](size_t n)
{
  auto p = check(n, "out of range");
  return (*p)[n];
}

const string &StrBlobPtr::operator[](size_t n) const
{
  auto p = check(n, "out of range");
  return (*p)[n];
}

StrBlobPtr &StrBlobPtr::operator++()
{
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

StrBlobPtr &StrBlobPtr::operator--()
{
  --curr;
  check(curr, "increment past end of StrBlobPtr");
  return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
  StrBlobPtr ret(*this);
  ++*this;
  return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
  StrBlobPtr ret(*this);
  --*this;
  return ret;
}

string &StrBlobPtr::operator*()
{
  auto p = check(curr, "dereference pass end");
  return (*p)[curr];
}

string *StrBlobPtr::operator->()
{
  return &this->operator*();
}

string &StrBlobPtr::deref() const
{
  auto p = check(curr, "deference pass end");
  return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
  check(curr, "increment pass end of StrBlobPtr");
  ++curr;
  return *this;
}

bool operator==(const StrBlobPtr &s1, const StrBlobPtr &s2)
{
  auto ret1 = s1.wptr.lock();
  if(!ret1)
    throw runtime_error("unbound StrBlobPtr");
  auto ret2 = s2.wptr.lock();
  if(!ret2)
    throw runtime_error("unbound StrBlobPtr");
  return *ret1 == *ret2;
}

bool operator!=(const StrBlobPtr &s1, const StrBlobPtr &s2)
{
  return !(s1 == s2);
}

bool operator<(const StrBlobPtr &s1, const StrBlobPtr &s2)
{
  auto ret1 = s1.wptr.lock();
  if(!ret1)
    throw runtime_error("unbound StrBlobPtr");
  auto ret2 = s2.wptr.lock();
  if(!ret2)
    throw runtime_error("unbound StrBlobPtr");
  return *ret1 < *ret2;
}

StrBlobPtr operator+(const StrBlobPtr &s1, size_t n)
{
  StrBlobPtr ret(s1);
  while(n)
    {
      ++ret;
      --n;
    }
  return ret;
}

StrBlobPtr operator-(const StrBlobPtr &s1, size_t n)
{
  StrBlobPtr ret(s1);
  while(n)
    {
      --ret;
      --n;
    }
  return ret;
}


// ConstStrBlobPtr member
const string &ConstStrBlobPtr::deref() const
{
  auto p = check(curr, "dereference pass end");
  return (*p)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incr()
{
  check(curr, "increment pass end of StrBlobPtr");
  ++curr;
  return *this;
}

const string &ConstStrBlobPtr::operator*()
{
  auto p = check(curr, "deference past end");
  return (*p)[curr];
}

const string *ConstStrBlobPtr::operator->()
{
  return &this->operator*();
}

StrBlobPtr StrBlob::begin()
{
  return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
  auto ret = StrBlobPtr(*this, data->size());
    return ret;
}
