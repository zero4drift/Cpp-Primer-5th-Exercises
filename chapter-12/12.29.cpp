// if using while(true), both behave exactly the same,
// if using while condition like below, it is better,
// simple and straight,
// but the drawback is this program would search "q" in text before exit.

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
