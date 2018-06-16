#include <string>

using std::string;
using std::size_t;

class HasPtr
{
public:
  HasPtr(const string &s = string()):
    ps(new string(s)), use(new size_t(1)), i(0) {}
  HasPtr(const HasPtr &h): ps(new string(*h.ps)), use(h.use),i(h.i) {++*use;}
  HasPtr &operator=(const HasPtr &);
  ~HasPtr();
private:
  string *ps;
  size_t *use;
  int i;
};

HasPtr::~HasPtr()
{
  if(--*use == 0)
    {
      delete ps;
      delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr &h)
{
  ++*h.use;
  if(--*use == 0)
    {
      delete ps;
      delete use;
    }
  ps = h.ps;
  i = h.i;
  use = h.use;
  return *this;
}
