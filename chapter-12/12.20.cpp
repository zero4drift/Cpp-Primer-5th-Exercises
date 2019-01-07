#include <string>
#include <iostream>
#include <fstream>
#include "StrBlob.hpp"

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::getline;

int main(int argc, char *argv[])
{
  if(argc != 2) return -1;
  ifstream ifs(argv[1]);
  if(!ifs) return -1;
  string s;
  StrBlob sb;
  while(getline(ifs, s))
    sb.push_back(s);
  StrBlobPtr beg = sb.begin();
  for(auto count = sb.size(); count > 0; --count)
    {
      cout << beg.deref() << endl;
      beg.incr();
    }
}
