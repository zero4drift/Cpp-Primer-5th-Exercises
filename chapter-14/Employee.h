#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;

class Employee;
istream &read(istream &is, Employee &e);

class Employee
{
  friend istream &read(istream &is, Employee &e);
  friend istream &operator>>(istream &is, Employee &e);
  friend ostream &operator<<(ostream &os, const Employee &e);
  friend bool operator==(const Employee &e1, const Employee &e2);
  friend bool operator!=(const Employee &e1, const Employee &e2);
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
 Employee(istream &is): Employee() {is >> *this;}
};

istream &read(istream &is, Employee &e)
{
  is >> e.name >> e.address >> e.contact
     >> e.department >> e.job;
  return is;
}

istream &operator>>(istream &is, Employee &e)
{
  is >> e.name >> e.address >> e.contact
     >> e.department >> e.job;
  if(!is)			/* In the old version, there was no check of is */
    e = Employee();
  return is;
}

ostream &operator<<(ostream &os, const Employee &e)
{
  os << e.name << " "
     << e.address << " "
     << e.contact << " "
     << e.department << " "
     << e.job;
  return os;
}

bool operator==(const Employee &e1, const Employee &e2)
{
  if(e1.name == e2.name &&
     e1.address == e2.address &&
     e1.department == e2.department &&
     e1.contact == e2.contact &&
     e1.job == e2.job)
    return true;
  else
    return false;
}

bool operator!=(const Employee &e1, const Employee &e2)
{
  return !(e1 == e2);
}
