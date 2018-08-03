struct Base
{
  void bar(int);
protected:
  int ival;
};

struct Derived1: virtual public Base
{
  void bar(char);
  void foo(char);
protected:
  char cval;
};

struct Derived2: virtual public Base
{
  void foo(int);
protected:
  int ival;
  char cval;
};

class VMI: public Derived1, public Derived2 {};

// without specifier:
// bar(Derived1), ival(Derived2);
// appears in one inheritance tree and hides the member with same name in base class;

// with specifier:
// Derived1::foo, Derived1:cval, Derived2::foo, Derived2::cval, Base::bar, Base::ival;
// appears in both inheritance trees, ambiguous problem.
