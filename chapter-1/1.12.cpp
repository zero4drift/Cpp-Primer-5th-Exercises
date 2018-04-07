#include <iostream>

int main()
{
  int sum = 0;
  for(int i = -100; i <= 100; ++i)
    sum += i;			// the result is appearantly 0
  return sum;
}
