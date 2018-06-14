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
 public:
  typedef vector<string>::size_type size_type;
  StrBlob();
  StrBlob(initializer_list<string> il);
  size_type size() const {return data->size();}
  bool empty() const {return data->empty();}
  void push_back(const string &t) {data->push_back(t);}
  void pop_back();
  string &front();
  const string &front() const;
  string &back();
  const string &back() const;
  StrBlobPtr begin();
    StrBlobPtr end();
 private:
  shared_ptr<vector<std::string>> data;
  void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il):
data(make_shared<vector<string>>(il)) {}

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

class StrBlobPtr
{
 public:
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

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
  auto ret = wptr.lock();
  if(!ret)
    throw runtime_error("unbound StrBlobPtr");
  if(i >= ret->size())
    throw out_of_range(msg);
  return ret;
}

string &StrBlobPtr::deref() const
{
  auto p = check(curr, "dereference pass end");
  return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
  check(curr, "increment pass end of StrBlobPtr");
  ++curr;
  return *this;
}

class ConstStrBlobPtr
{
 public:
 ConstStrBlobPtr(): curr(0) {}
 ConstStrBlobPtr(const StrBlob &a, size_t sz = 0):
  wptr(a.data), curr(sz) {}
  const string &deref() const;
  ConstStrBlobPtr &incr();
 private:
  shared_ptr<vector<string>> check(size_t,const string&) const;
  weak_ptr<vector<string>> wptr;
  size_t curr;
};

shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string &msg) const
{
  auto ret = wptr.lock();
  if(!ret)
    throw runtime_error("unbound StrBlobPtr");
  if(i >= ret->size())
    throw out_of_range(msg);
  return ret;
}

string &ConstStrBlobPtr::deref() const
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

StrBlobPtr StrBlob::begin()
{
  return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
  auto ret = StrBlobPtr(*this, data->size());
    return ret;
}
