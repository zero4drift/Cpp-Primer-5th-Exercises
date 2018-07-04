#include <iostream>
#include <string>

using std::cin;
using std::istream;
using std::getline;
using std::string;

class ReadString
{
  istream &is;
public:
  ReadString(istream &i = cin): is(i) {};
  string operator()() const;
};

string ReadString::operator()() const
{
  string result;
  getline(is, result);
  if(is)
    return result;
  else
    return "";
}
