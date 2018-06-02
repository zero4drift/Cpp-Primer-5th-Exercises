// for vector, if do not assign the return value to begin, begin would be a invalid iterator, causes a run time error,

#include <vector>

using std::vector;

int main()
{
  vector<int> v = {1, 2, 3, 4, 5};
  auto beg = v.begin();
  while(beg != v.end())
    {
      ++beg;
      v.insert(beg, 42);	// segment fault
      ++beg;
    }
}
