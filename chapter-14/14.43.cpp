#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>

using std::vector;
using std::modulus;
using std::placeholders::_1;
using std::cin;
using std::cout;
using std::endl;
using std::find_if;

int main()
{
  int i;
  vector<int> vi;
  cout << "Please input integers: " << endl;
  while(cin >> i)
    vi.push_back(i);
  cin.clear();
  int j;
  cout << "Please input a interger to test: " << endl;
  cin >> j;
  auto modulus_left = bind(modulus<int>(), j, _1);
  auto iter = find_if(vi.cbegin(), vi.cend(), modulus_left);
  if(iter == vi.cend())
    cout << "ok" << endl;
  else
    cout << "bad" << endl;
}

