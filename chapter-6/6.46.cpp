// it is possibile

#include <string>

using std::string;

constexpr bool isShorter(const string &s1, const string &s2)
{
  return s1.size() < s2.size() ? true : false;
}
