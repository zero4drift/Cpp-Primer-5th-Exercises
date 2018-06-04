#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::count;

int main()
{
  int i;
  vector<int> vi;
  while(cin >> i)
    vi.push_back(i);
  cout << "Specify a number: " << endl;
  cin.clear();
  cin >> i;
  cout << "There are " << count(vi.begin(), vi.end(), i)
       << " count of " << i << " in input numbers" << endl;
}
