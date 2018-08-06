#include <string>
#include <iostream>
#include "Screen.h"

using std::string;
using std::cout;
using std::endl;

int main()
{
  Screen s;
  const Screen::pos Screen::*p;
  // Move data member cusrsro to public member to simplify code
  p = &Screen::cursor;
  cout << s.*p << endl;
}
