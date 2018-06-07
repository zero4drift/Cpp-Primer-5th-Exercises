#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

using std::unique_copy;
using std::vector;
using std::inserter;
using std::cout;
using std::cin;
using std::endl;

int main()
{
  cout << "Please enter integers: " << endl;
  vector<int> vi1;
  int i;
  while(cin >> i)
    vi1.push_back(i);
  if(!vi1.size()) return -1;
  vector<int> vi2;
  unique_copy(vi1.cbegin(), vi1.cend(), inserter(vi2, vi2.begin()));
  cout << "Unique integers among your inputs: " << endl;
  for(const auto &i : vi2)
    cout << i << endl;
}
