#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  char c;
  unsigned cnt = 0;
  cout << "Please enter words or specify a text file: " << endl;
  while(cin >> c)
      if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ++cnt;
  cout << "There're " << cnt << " aeiou characters." << endl;
}
