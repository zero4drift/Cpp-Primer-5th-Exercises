#ifndef EMPLOYEE_H
#define EMPLOYEE_H


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
  Employee &operator=(const Employee &);
  Employee &operator=(Employee &&) noexcept;
  Employee &operator=(const string &);
};


#endif
