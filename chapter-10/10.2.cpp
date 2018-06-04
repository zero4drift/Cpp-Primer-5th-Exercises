#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;
using std::count;

int main()
{
  string i;
  vector<string> vs;
  while(cin >> i)
    vs.push_back(i);
  cout << "Specify a string: " << endl;
  cin.clear();
  cin >> i;
  cout << "There are " << count(vs.begin(), vs.end(), i)
       << " count of " << i << " in input strings" << endl;
}
