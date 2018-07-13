#include <iostream>

using std::cout;
using std::endl;
using std::ostream;
using std::istream;

template <unsigned L, unsigned W> class Screen;

template <unsigned L, unsigned W> ostream &operator<<(ostream &os, Screen<L, W> s){
  os << "Length " << s.length
       << "Width " << s.width;
  return os;
}

template <unsigned L, unsigned W> istream &operator>>(istream &is, Screen<L, W> s){
  is >> s.length >> s.width;
  return is;
}

template <unsigned L, unsigned W>
class Screen
{
  // operator<< access private member of instance of this template
  // both class and function instantiated by same template nontype arguments.
  friend ostream &operator<<<L, W>(ostream &, Screen<L, W>);
  // operator>> access private member of instance of this template
  // both class and function instantiated by same template nontype arguments.
  friend istream &operator>><L, W>(istream &, Screen<L, W>);
  unsigned lenth = L;
  unsigned width = W;
};
