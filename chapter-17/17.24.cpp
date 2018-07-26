#include <regex>
#include <string>
#include <iostream>

using std::regex;
using std::smatch;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::regex_replace;

int main()
{
  string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
  regex r(phone);
  smatch m;
  string s;
  string fmt = "$2.$5.$7";
  while(getline(cin, s))
    cout << regex_replace(s, r, fmt) << endl;
}
