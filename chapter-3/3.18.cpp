#include <vector>

using std::vector;

int main()
{
  vector<int> ivec;
  // ivec[0] = 42; illegal, ivec is empty now, ivec[0] is undefinied
  ivec.push_back(42);
}
