#include <iostream>

using std::cin;
using std::cout;
using std::cout;
using std::endl;

int main()
{
  int i;
  cout << "Please enter integer number one by one succeded by enter: "
       << endl;
  while(cin >> i) if(i == 42) return 0;
}
