#include "My_unique_ptr.h"
#include "DebugDelete.h"

int main()
{
  My_unique_ptr<int> m1;
  My_unique_ptr<int, DebugDelete> m2(new int(),DebugDelete());
}
