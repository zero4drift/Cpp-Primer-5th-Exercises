#include <iostream>

using std::cout;
using std::endl;

class A
{
public:
  virtual ~A() {}
};

class B: public A {};

class C: public B {};

int main()
{
  A *pa = new C;
  cout << typeid(pa).name() << endl; // A*
  C cobj;
  A &ra = cobj;
  cout << typeid(&ra).name() << endl; // A*
  B *px = new B;
  A &ra2 = *px;
  cout << typeid(ra2).name() << endl; // B 
}
