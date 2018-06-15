#include <iostream>

using std::cout;
using std::endl;

struct X
{
  X() {cout << "X()" << endl;}
  X(const X &) {cout << "X(const X &)" << endl;}
  X &operator=(const X &) {cout << "X &operator=(const X &x)" << endl;}
  ~X() {cout << "~X()" << endl;}
};

void test1(X &) {}
void test2(X) {}

int main()
{
  X x1;
  X x2 = x1;
  X *p = new X;
  test1(x1);
  test2(x1);
  X ax[] = {x1, x2, *p};
  delete p;
}
