#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using std::istream;
using std::ostream;
using std::string;

struct Person {
  friend istream &read(istream &, Person &);
public:				/* These member functions and constructors are nececssary to be accessibile to users, they're interfaces of this class */
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
  Person(istream &);
private:			/* data members of class shoud not be accessed directly */
  string name;
  string address;
};

istream &read(istream &is, Person &p);
ostream &print(ostream &os, Person &p);

#endif
