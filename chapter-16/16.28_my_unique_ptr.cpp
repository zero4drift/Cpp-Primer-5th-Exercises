#include <iostream>
#include "My_unique_ptr.hpp"
#include "DebugDelete.hpp"

using std::cout;
using std::endl;

void my_delete(int *p)
{
  cout << "function my_delete" << endl;
  delete p;
}

int main()
{
  My_unique_ptr<int> m1;
  My_unique_ptr<int, DebugDelete> m2(new int(), DebugDelete());
  My_unique_ptr<int, decltype(my_delete)*> m3(new int(), my_delete);
}
