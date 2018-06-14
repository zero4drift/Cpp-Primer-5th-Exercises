// See TextQuery.h

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
  while(true)
    {
      cout << "Enter word to look for, or q to quit: ";
      string s;
      if(!(cin >> s) || s == "q") break;
      print(cout, tq.query(s)) << endl;
    }
}

int main(int argc, char *argv[])
{
  ifstream ifs(argv[1]);
  runQueries(ifs);
}

