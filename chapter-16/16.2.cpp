#include "Sales_data.hpp"

template <typename T>
int compare(const T &v1, const T &v2)
{
  if(v1 < v2) return -1;
  if(v2 < v1) return 1;
  return 0;
}

int main()
{
  compare(1, 2);
  // compare(Sales_data(), Sales_data());
  // compiler error:
  // ...
  // no match for 'operator<' ...
}
