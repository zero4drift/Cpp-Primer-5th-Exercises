#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::stoi;
using std::stod;
using std::cout;
using std::endl;

int main()
{
  vector<string> vsi = {"1", "2", "3"};
  int sum = 0;
  for(const auto &s : vsi)
    sum += stoi(s.substr(s.find_first_of("+-0123456789")));
  cout << sum << endl;

  vector<string> vsd = {"1.1", "2.2", "3.3"};
  double d_sum = 0.0;
  for(const auto &s : vsd)
    d_sum += stod(s.substr(s.find_first_of("+-.0123456789")));
  cout << d_sum << endl;
}
