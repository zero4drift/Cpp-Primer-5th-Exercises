#include <vector>
#include <string>
#include <iostream>
#include "14.35.h"

using std::vector;
using std::string;
using std::cin;

int main()
{
  vector<string> vs;
  ReadString rs;
  string result;
  while((result = rs()) != "")
    vs.push_back(result);
}
