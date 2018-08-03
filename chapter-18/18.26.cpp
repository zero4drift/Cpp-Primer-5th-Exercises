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
protected:
  int *ival;
  vector<double> dvec;
};

int main()
{
  MI mi;
  mi.print(42);
  // for original classes, this expression would try to call MI::print(vector<double>), while literal int 42 could not be converted to such a type, which would fail in type check and causes a error. 
}
