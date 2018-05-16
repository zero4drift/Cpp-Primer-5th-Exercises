#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using std::istream;
using std::ostream;
using std::string;

struct Person {
  string get_name() const {return name;}
  string get_address() const {return address;}
  /*
   * shuld be const member functions
   * which makes them more flexible
   * for both functions just return but not modify the member of a object
   * and const object of Person type could also be able to call this kind of functions
   */
  Person() = default;
Person(const string &s1, const string &s2): name(s1), address(s2) {};
  string name;
  string address;
};

istream &read(istream &is, Person p)
{
  is >> p.name >> p.address;
  return is;
}

ostream &print(ostream &os, Person p)
{
  os << p.get_name() << " " << p.get_address();
  return os;
}

#endif
