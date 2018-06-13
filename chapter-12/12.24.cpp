#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::size_t;

int main()
{
  /* using unique_ptr<char[]> p(new char[length]
     would make this program much easier */
  constexpr size_t length = 10;
  char *p = new char[length];
  string s;
  cin >> s;
  size_t count;
  if(s.length() > length)
    count = length;
  else
    count = s.length();
  for(size_t index = 0; index < count; ++index)
    *(p + index) = s[index];
  // check
  for(size_t index = 0; index < length; ++index)
    cout << *(p + index);
  cout << endl;
  delete [] p;
}
