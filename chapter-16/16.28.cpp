// See My_shared_ptr.h and My_unique_ptr.h.

#include <fstream>
#include <iostream>
#include <string>
#include "TextQuery.h"

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;
using std::string;

void runQueries(ifstream &infile)
{
  TextQuery tq(infile);
  string s;
  do
    {
      cout << "Enter word to look for, or q to quit: ";
      cin >> s;
      print(cout, tq.query(s)) << endl;
    }
  while(cin && s != "q");
}

int main(int argc, char *argv[])
{
  ifstream ifs(argv[1]);
  runQueries(ifs);
}
