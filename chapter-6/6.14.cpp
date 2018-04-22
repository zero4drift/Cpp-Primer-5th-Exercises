#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int called_cnt(int &cnt)	// calculate the times a function is called
{
  return ++cnt;
}

unsigned abs_value(int i)	// calculate the abs value of one integer, the original argument maybe required in the later context
{
  return i >= 0 ? i : -i;
}
