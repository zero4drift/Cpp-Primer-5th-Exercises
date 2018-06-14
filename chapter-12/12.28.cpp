#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

using std::ifstream;
using std::istringstream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::set;
using std::vector;
using std::string;
using std::set;
using std::size_t;
using std::getline;


void read_parse(vector<string> &text, map<string, set<size_t>> &results, ifstream &infile)
{
  size_t line_number = 0;
  string line;
  while(getline(infile, line))
    {
      // store line in vector<string>
      text.push_back(line);
      // scan through the line      
      istringstream ist(line);
      string word;
      while(ist >> word)
	results[word].insert(line_number);
      // increase the line_number
      ++line_number;
    }
}

ostream &print(ostream &o, const string &s, const vector<string> &text, const map<string, set<size_t>> results)
{
  set<size_t> line_number;
  auto iter = results.find(s), last = results.end();
  if(iter != last) line_number = iter->second;
  o << "element occurs " << line_number.size() << " times" << endl;
  if(line_number.size())
    {
      for(const auto &l : line_number)
	cout << "        (line " << l + 1 << ") "
	     << text[l] << endl;
    }
  return o;
}

void runQueries(ifstream &infile)
{
  vector<string> text;
  map<string, set<size_t>> results;
  read_parse(text, results, infile);
  while(true)
    {
      cout << "Enter word to look for, or q to quit: ";
      string s;
      if(!(cin >> s) || s == "q") break;
      print(cout, s, text, results) << endl;
    }
}

int main(int argc, char *argv[])
{
  ifstream ifs(argv[1]);
  runQueries(ifs);
}
