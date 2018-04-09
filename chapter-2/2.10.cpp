#include <iostream>

std::string global_str;		// ""
int global_int;			// 0

int main()
{
  int local_int;		// undefined
  std::string local_str;	// initialized by class string
  std::cout << global_str << '\n'
	    << global_int << '\n'
	    << local_int  << '\n'
	    << local_str  << std::endl;
  return 0;
}
