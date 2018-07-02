#include <string>
#include <iostream>
#include "Employee.h"

using std::string;
using std::ostream;
using std::istream;

istream &read(istream &is, Employee &e)
{
  is >> e.name >> e.address >> e.contact
     >> e.department >> e.job;
  return is;
}

Employee &Employee::operator=(const Employee &e)
{
  name = e.name;
  address = e.address;
  contact = e.contact;
  department = e.department;
  job = e.job;
  return *this;
}

Employee &Employee::operator=(Employee &&e) noexcept
{
  name = std::move(e.name);
  address = std::move(e.address);
  contact = std::move(e.contact);
  department = std::move(e.department);
  job = std::move(e.job);
  return *this;
}

Employee &Employee::operator=(const string &s)
{
  name = s;
  address = contact = department = job = "";
  return *this;
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
