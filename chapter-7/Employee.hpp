#include <string>
#include <iostream>

using std::string;
using std::istream;

class Employee;
istream &read(istream &is, Employee &e);

class Employee
{
  friend istream &read(istream &is, Employee &e);
  using str = string;
  str name;
  str address;
  str contact;
  str department;
  str job;
 public:
 Employee(): Employee("") {};
 Employee(str n, str a = "", str c = "", str d = "", str j = ""):
  name(n), address(a), contact(c),  department(d), job(j) {}
  // Exercise 7.40: An Employee object better has a name, left could be filled later
  // And compiler could be able to distinguish above two constructors
 Employee(istream &is): Employee() {read(is, *this);}
};

istream &read(istream &is, Employee &e)
{
  is >> e.name >> e.address >> e.contact
     >> e.department >> e.job;
  return is;
}
