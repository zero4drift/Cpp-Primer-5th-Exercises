#ifndef PERSON_H
#define PERSON_H

#include <string>

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
  string name;
  string address;
};

#endif
