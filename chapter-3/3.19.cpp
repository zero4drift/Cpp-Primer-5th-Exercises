#include <vector>

using std::vector;

int main()
{
  vector<int> v1(10, 42);	// that's better, easy to use and understand
  vector<int> v2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
  vector<int> v3(10);
  for(unsigned i = 0; i != 10; ++i)
    v3.push_back(42);
}
