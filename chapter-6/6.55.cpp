#include <vector>

using std::vector;

int func1(int a, int b)
{
  return a + b;
}

int func2(int a, int b)
{
  return a - b;
}

int func3(int a, int b)
{
  return a * b;
}

int func4(int a, int b)
{
  return a / b;
}

vector<int(*)(int, int)> fv{func1, func2, func3, func4};
