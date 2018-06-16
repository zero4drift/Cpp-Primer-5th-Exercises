#include <iostream>

using std::cout;
using std::endl;

struct numbered1
{
  int mysn;
};

struct numbered2
{
  int mysn;
  numbered2(const numbered2 &n): mysn(n.mysn + 1) {}
  numbered2(): mysn(0) {}
};

void f1(numbered1 s) {cout << s.mysn << endl;}

void f2(numbered2 s) {cout << s.mysn << endl;}

void f3(const numbered2 &s) {cout << s.mysn << endl;}

int main()
{
  // first
  numbered1 a1, b1 = a1, c1 = b1;
  f1(a1);
  f1(b1);
  f1(c1);
  // second
  numbered2 a2, b2 = a2, c2 = b2;
  f2(a2);
  f2(b2);
  f2(c2);
  // third
  f3(a2);
  f3(b2);
  f3(c2);
}
