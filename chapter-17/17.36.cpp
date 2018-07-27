#include <cmath>
#include <iostream>
#include <iomanip>

using std::sqrt;
using std::cout;
using std::fixed;
using std::scientific;
using std::hexfloat;
using std::defaultfloat;
using std::uppercase;
using std::nouppercase;
using std::setw;

int main()
{
  cout << setw(20) << 100 * sqrt(2.0) << '\n'
       << scientific << setw(20) << 100 * sqrt(2.0) << '\n'
       << fixed << setw(20) << 100 * sqrt(2.0) << '\n'
       << hexfloat << uppercase << setw(20)
       << 100 * sqrt(2.0) << '\n' << nouppercase
       << defaultfloat << setw(20)
       <<  100 * sqrt(2.0) << '\n';
}

