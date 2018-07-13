#include <string>
#include <vector>
#include <memory>
#include <exception>

using std::string;
using std::size_t;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using std::initializer_list;
using std::runtime_error;
using std::out_of_range;

template <typename T> class BlobPtr;

template <typename T> class Blob
{
  friend class BlobPtr<T>;
 public:
  typedef typename vector<T>::size_type size_type;
  Blob();
  Blob(initializer_list<T> il);
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
  shared_ptr<vector<T>> data;
  void check(size_type i, const string &msg) const;
};

template <typename T> Blob<T>::Blob(): data(make_shared<vector<T>>()) {}
template <typename T> Blob<T>::Blob(initializer_list<T> il):
data(make_shared<vector<T>>(il)) {}

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
  return a.wptr == b.wptr;
}

template <typename T> class BlobPtr
{
  friend bool operator==<T>(const BlobPtr<T> &, const BlobPtr<T> &);
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
  shared_ptr<vector<T>> check(size_t,const string&) const;
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

template <typename T> shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string &msg) const
{
  auto ret = wptr.lock();
  if(!ret)
    throw runtime_error("unbound BlobPtr");
  if(i >= ret->size())
    throw out_of_range(msg);
  return ret;
}

