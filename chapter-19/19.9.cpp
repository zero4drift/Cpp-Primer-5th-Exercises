#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

struct Base {virtual ~Base() {}};
struct Derived: public Base {};

string name_transfer(const string &s)
{
  string result;
  if(s == "i")
    result = "int"; 
  else if(s == "A10_i")
    result = "int array[10]";
  else if(s == "NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE")
    result = "string";
  else if(s == "P4Base")
    result = "Base*";
  else if(s == "7Derived")
    result = "Derived";
  return result;
}

int main()
{
  int arr[10];
  Derived d;
  Base *p = &d;

  cout << name_transfer(typeid(42).name()) << ", "
       << name_transfer(typeid(arr).name()) << ", "
       << name_transfer(typeid(string).name()) << ", "
       << name_transfer(typeid(p).name()) << ", "
       << name_transfer(typeid(*p).name()) << endl;
}
