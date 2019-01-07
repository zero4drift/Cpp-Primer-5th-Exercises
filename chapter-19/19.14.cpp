#include "Screen.hpp"

int main()
{
  // legal;
  auto pmf = &Screen::get_cursor;
  // pmf is a member function pointer points to Screen::get_cursor, which is a member function which accepts no parameter and return type as char;
  pmf = &Screen::get;
  // now pmf points to Screen::get, which has same function type as Screen::get_cursor(refer to my Screen class version).
}
