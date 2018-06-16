#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::sort;

class HasPtr
{
  friend void swap(HasPtr &, HasPtr &);
public:
  HasPtr(const string &s = string()):
    ps(new string(s)), i(0) {}
  HasPtr(const HasPtr &h): ps(new string(*h.ps)), i(h.i) {}
  HasPtr &operator=(HasPtr);
  bool operator<(HasPtr &);
  ~HasPtr() {delete ps;};
private:
  string *ps;
  int i;
};

bool HasPtr::operator<(HasPtr &h)
{
  return *ps < *(h.ps);
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

HasPtr& HasPtr::operator=(HasPtr h)
{
  swap(*this, h);
  return *this;
}

int main()
{
  vector<HasPtr> vh;
  vh.push_back(HasPtr("hello"));
  vh.push_back(HasPtr("you"));
  vh.push_back(HasPtr("me"));
  sort(vh.begin(), vh.end());
}
