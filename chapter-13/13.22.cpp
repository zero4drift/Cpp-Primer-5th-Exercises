#include <string>

using std::string;

class HasPtr
{
public:
  HasPtr(const string &s = string()):
    ps(new string(s)), i(0) {}
  HasPtr(const HasPtr &h): ps(new string(*h.ps)), i(h.i) {}
  HasPtr &operator=(const HasPtr &);
  ~HasPtr() {delete ps;};
private:
  string *ps;
  int i;
};

HasPtr& HasPtr::operator=(const HasPtr &h)
{
  auto newptr = new string(*h.ps);
  delete ps;
  ps = newptr;
  i = h.i;
  return *this;
}
