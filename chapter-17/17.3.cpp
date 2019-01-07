// See TextQuery.h.
// if class QueryResult would not be utilized in another place;
// Using tuple instead of a class definition is a better choice;
// reduce complexity and save labor work.

#include <fstream>
#include <iostream>
#include <string>
#include "TextQuery.hpp"

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;
using std::string;

void runQueries(ifstream &infile)
{
  TextQuery tq(infile);
  string s;
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

