#include <string>

using std::string;

class HasPtr
{
public:
  HasPtr(const string &s = std::string()):
    ps(new string(s)), i(0) {}
  HasPtr(const HasPtr &h): ps(new string), i(h.i) {*ps = *h.ps;}
private:
  string *ps;
  int i;
};
