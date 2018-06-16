#include <string>

using std::string;

class Employee
{
  static unsigned seed;
  string name;
  unsigned id = 0;
 public:
 Employee(): id(++seed) {}
 Employee(string n): name(n), id(++seed) {}
 Employee(const Employee &e): name(e.name), id(++seed) {}
  Employee &operator=(const Employee &e);
};

unsigned Employee::seed = 0;
Employee& Employee::operator=(const Employee &e)
{
  name = e.name;
  id = ++seed;
  return *this;
}
