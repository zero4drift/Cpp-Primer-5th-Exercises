#include <vector>

using std::vector;

int main()
{
  vector<int> v1;
  const vector<int> v2;
  auto it1 = v1.begin(), it2 = v2.begin(); // illegal see P61 2.5.2
  auto it3 = v1.cbegin(), it4 = v2.cbegin(); // both const_iterator
}
