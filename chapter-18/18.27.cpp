#include <string>
#include <vector>

using std::string;
using std::vector;

struct Base1
{
  void print(int) const;
protected:
  int ival;
  double dval;
  char cval;
private:
  int *id;
};

struct Base2
{
  void print(double) const;
protected:
  double fval;
private:
  double dval;
};

struct Derived: public Base1
{
  void print(string) const;
protected:
  string sval;
  double dval;
};

struct MI: public Derived, public Base2
{
  void print(vector<double>);
  void print(int i) {Base1::print(i);}
  void foo(double);
protected:
  int *ival;
  vector<double> dvec;
};

int ival;
double dval;
void MI::foo(double cval)
{
  int dval;
}

// (a):
// ::ival, ::dval;
// MI::ival, MI::dvec, MI::print(vector<double>), MI::print(int);
// Derived::print(string), Derived::sval, Derived::dval;
// Base2::print(double), Base2::fval;
// Base1::print(int), Base1::ival, Base1::dval, Base1::cval;

// (b):
// print

// (c)
// dval = Base1::dval + Derived::dval;

// (d)
// Base2::fval = *dvec.rbegin();

// (e)
// Derived::sval[0] = Base1::cval;

