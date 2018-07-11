#include <string>
#include <iostream>

using std::string;
using std::ostream;

class base
{
public:
  string name() {return basename;}
  virtual void print(ostream &os) {os << basename;};
private:
  string basename;
};

class derived: public base
{
public:
  // void print(ostream &os) {print(os); os << " " << i;} // call itself within function body causes infinite recursion.
  void print(ostream &os) override {base::print(os); os << " " << i;}
private:
  int i;
};
