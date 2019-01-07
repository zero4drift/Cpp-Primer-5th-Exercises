#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class HasPtr
{
  friend void swap(HasPtr &, HasPtr &);
 public:
 HasPtr(const string &s = string()): ps(new string(s)), i(0) {}
  HasPtr(HasPtr &&h) noexcept: ps(h.ps), i(h.i) {h.ps = nullptr;}
 HasPtr(const HasPtr &h): ps(new string(*h.ps)), i(h.i) {}
  HasPtr &operator=(const HasPtr &);
  HasPtr &operator=(HasPtr &&) noexcept;
  ~HasPtr() {delete ps;};
 private:
  string *ps;
  int i;
};


HasPtr& HasPtr::operator=(HasPtr &&h) noexcept
{
  if(this != &h)
    {
      delete ps;
      ps = h.ps;
      i = h.i;
      h.ps = nullptr;
    }
  return *this;
}

void swap(string *p1, string *p2)
{
  string *temp = p1;
  p1 = p2;
  p2 = temp;
}

void swap(HasPtr &h1, HasPtr &h2)
{
  cout << "swap(HasPtr &h1, HasPtr &h2)" << endl;
  using std::swap;
  swap(h1.ps, h2.ps);
  swap(h1.i, h2.i);
}

HasPtr& HasPtr::operator=(const HasPtr& h)
{
  // swap(*this, h);
  ps = new string(*h.ps);
  i = h.i;
  return *this;
}
