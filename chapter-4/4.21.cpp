#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
  vector<int> iv;
  int i;
  cout << "Please enter integer numbers: " << endl;
  while(cin >> i) iv.push_back(i);
  for(auto &i : iv) ((i % 2) ? (i *= 2) : i);
  for(auto &i : iv) cout << i << endl;
}
