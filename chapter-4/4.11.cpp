#include <iostream>

using std::cin;
using std::cout;
using std::cout;
using std::endl;

int main()
{
  int a, b, c, d;
  cout << "Please enter four integer numbers in descending order: "
       << endl;
  cin >> a >> b >> c >> d;
  if(a > b && b > c && c > d) cout << "Good boy" << endl;
  else cout << "False" << endl;
}
