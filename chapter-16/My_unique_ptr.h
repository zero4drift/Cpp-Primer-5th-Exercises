#ifndef MY_UNIQUE_PTR_H
#define MY_UNIQUE_PTR_H


#include <iostream>

using std::cout;
using std::endl;

template <typename T> class Delete
{
 public:
  void operator()(T *p)
  {
    delete p;
    cout << "class Delete" << endl;
  }
};

template <typename T, typename U = Delete<T>> class My_unique_ptr
  {
  public:
  My_unique_ptr(): p(new T()) {}
  My_unique_ptr(T *q): p(q) {}
  My_unique_ptr(T *q, U d): p(q), del(d) {}
  void reset() {del(p); p = nullptr;}
  void reset(T *q) {del(p); p = q;};
  ~My_unique_ptr() {del(p);}
  My_unique_ptr(const My_unique_ptr &m) = delete;
  My_unique_ptr &operator=(const My_unique_ptr &m) = delete;
  private:
  T *p;
  U del;
  };


#endif
