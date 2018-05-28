#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using std::ifstream;
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
  if(argc != 2) cout << "Incorrect command-line args" << endl; 
  string word;
  vector<string> vs;
  ifstream input;
  input.open(argv[argc - 1]);
  if(input)
    while(input >> word)
      vs.push_back(word);
  else
    cout << "Open file failed, please check the input file name!" << endl;
  for(auto &s : vs)
    cout << s << endl;
}
