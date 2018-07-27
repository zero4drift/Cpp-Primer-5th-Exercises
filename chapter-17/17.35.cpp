#include <cmath>
#include <iostream>

using std::sqrt;
using std::cout;
using std::fixed;
using std::scientific;
using std::hexfloat;
using std::defaultfloat;
using std::uppercase;
using std::nouppercase;

int main()
{
  cout << "default format: " << 100 * sqrt(2.0) << '\n'
       << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
       << "fix decimal: " << fixed << 100 * sqrt(2.0) << '\n'
       << "hexadecimal: " << hexfloat << uppercase << 100 * sqrt(2.0) << '\n'
       << nouppercase
       << "use defaults: " << defaultfloat << 100 * sqrt(2.0) << '\n';
}


