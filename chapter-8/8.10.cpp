#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cerr;
using std::ifstream;
using std::istringstream;
using std::string;
using std::getline;
using std::vector;

int main(int argc, char *argv[])
{
  if(argc != 2)
    {
      cerr << "Incorrect command-line args, needs 2 arguments, now "
	   << argc << endl;
      return -1;
    }
  ifstream ifs(argv[argc - 1]);
  string s, w;
  vector<string> vs;
  while(getline(ifs, s))
    vs.push_back(s);
  istringstream ist;
  for(const auto &sl : vs)
    {
      ist.str(sl);
      while(ist >> w) 
	cout << w << endl;
      ist.clear();
    }
}
