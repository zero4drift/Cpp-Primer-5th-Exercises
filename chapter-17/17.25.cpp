#include <iostream>
#include <fstream>
#include <sstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

using std::ifstream;
using std::string;
using std::getline;
using std::fstream;
using std::istringstream;
using std::vector;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::regex;
using std::smatch;

bool valid(const smatch& m)
{
  if(m[1].matched)
    return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
  else
    return !m[3].matched && m[4].str() == m[6].str();
}

struct PersonInfo
{
  string name;
  string phones;
};

int main(int argc, char *argv[])
{
  if(argc != 2)
    {
      cerr << "Incorrect command-line args, needs 2 now "
	   << argc << endl;
      return -1;
    }
  ifstream ifs(argv[argc - 1]);
  if(!ifs)
    {
      cerr << "Invalid arg " << argv[argc - 1] << endl;
      return -1;
    }
  string line, word;
  vector<PersonInfo> people;
  istringstream record;
  while(getline(ifs, line))
    {
      PersonInfo info;
      record.str(line);
      record >> info.name;
      info.phones = line.substr(info.name.size());
      people.push_back(info);
      record.clear();
    }
  // regex
  string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
  regex r(phone);
  smatch m;

  for(const auto &entry : people)
    {
      if(regex_search(entry.phones, m, r))
	{
	  if(valid(m))
	    cout << entry.name << m.str() << endl;
	  else
	    cerr << "input error: " << entry.name
		 << " invalid number(s) " << m.str() << endl;
	}
    }
}
