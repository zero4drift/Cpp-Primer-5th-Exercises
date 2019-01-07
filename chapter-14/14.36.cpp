#include <vector>
#include <string>
#include <iostream>
#include "14.35.hpp"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
  vector<string> vs;
  ReadString rs;
  string result;
  while((result = rs()).size())
    vs.push_back(result);
  for(const auto &i : vs)
    cout << i << endl;
}
