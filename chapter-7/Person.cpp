#include "Person.hpp"

istream &read(istream &is, Person &p)
{
  is >> p.name >> p.address;
  return is;
}

ostream &print(ostream &os, Person &p)
{
  os << p.get_name() << " " << p.get_address();
  return os;
}

Person::Person(istream &is)
{
  read(is, *this);
}
