#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::count;

template <typename T>
size_t count_in_vector(const vector<T> &vt, const T i)
{
  return count(vt.begin(), vt.end(), i);
}

template <>
size_t count_in_vector(const vector<const char *> &vt, const char *const i)
{
  size_t n;
  for(auto iter = vt.begin(); iter != vt.end(); ++iter)
    {
      if(strcmp(i, *iter) == 0)
	++n;
    }
  return n;
}

int main()
{
  vector<double> vd = {1.1, 2.2, 3.3, 4.4};
  vector<int> vi = {1, 2, 3, 4, 5};
  vector<string> vs = {string("hello"), string("world")};
  cout << count_in_vector(vd, 2.2) << endl;
  cout << count_in_vector(vi, 2) << endl;
  cout << count_in_vector(vs, "hello") << endl;
  cout << "Exercise 16.64:" << endl;
  vector<const char *> vc = {"hello", "world"};
  cout << count_in_vector(vc, "world") << endl;
}
