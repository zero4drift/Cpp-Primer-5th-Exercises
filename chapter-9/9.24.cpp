#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int main()
{
  vector<int> iv;
  cout << iv.front() << endl;	// segment fault
  cout << iv.back() << endl;	// same
  cout << iv[0] << endl;	// same
  cout << iv.at(0) << endl;	// std::out_of_range
}
