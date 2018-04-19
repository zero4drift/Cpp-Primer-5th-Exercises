#include <iostream>

int main()
{
  int sum = 0, val = 1;
  while(val <= 10)
    sum += val, ++val;		// less friendly, said in chapter4 that the evaluation of operands in one expression is not ordered, that this expression statement may results undefined behaviour 
  std::cout << "Sum of 1 t 10 inclusive is "
	    << sum << std::endl;
  return 0;
}
