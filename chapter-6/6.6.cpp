#include <iostream>

using std::cout;
using std::endl;

// parameter and local variable are both automatic object, while parameter is defined at the beginning of function calling process, local variable are defined later, which is obvious that parameter list is placed behind the function name, local variable is located in the function body

// local static object is defined inside function body but it would not be perished even the function ends, it would be so only when the whole program terminates; the definition statement of local static object would be skipped when this certain function be recalled.

unsigned abs_value(int i)
{
  unsigned result;
  result = (i >= 0) ? i : -i;
  cout << "The abs value of " << i << " is: " << result << endl; 
  static unsigned count = 0;
  return ++count;
}
