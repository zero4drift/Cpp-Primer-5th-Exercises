#include <string>

using std::string;

class HasPtr
{
public:
  HasPtr(const string &s = std::string()):
    ps(new string(s)), i(0) {}
  HasPtr(const HasPtr &h): ps(new string), i(h.i) {}
  HasPtr &operator=(const HasPtr &);
  ~HasPtr() {};
private:
  string *ps;
  int i;
};

HasPtr& HasPtr::operator=(const HasPtr &h)
{
  ps = new string(*h.ps);
  i = h.i;
  return *this;
}
