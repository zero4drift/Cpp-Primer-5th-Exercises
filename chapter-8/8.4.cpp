#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using std::ifstream;
using std::vector;
using std::string;
using std::getline;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
  string line;
  vector<string> vs;
  ifstream input;
  input.open(argv[argc - 1]);
  if(input)
    while(getline(input, line))
      vs.push_back(line);
  else
    cout << "Open file failed, please check the input file name!" << endl;
  for(auto &s : vs)
    cout << s << endl;
}
