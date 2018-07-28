// Really an odd way to solve this exercise.
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

using std::istringstream;
using std::ostringstream;
using std::ifstream;
using std::string;
using std::getline;
using std::vector;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::regex;
using std::smatch;
using std::sregex_iterator;
using std::regex_replace;
using std::regex_constants::format_first_only;

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
      info.phones = line.substr(info.name.size() + 1);
      people.push_back(info);
      record.clear();
    }
  // regex
  string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
  regex r(phone);

  for(auto &entry : people)
    {
      if(entry.phones.size() > 10)
	entry.phones = regex_replace(entry.phones, r, "", format_first_only);
      ostringstream formatted, badNums;
      for(sregex_iterator it(entry.phones.begin(), entry.phones.end(), r), end_it; it != end_it; ++it)
	if(!valid(*it))
	  badNums << " " << it->str();
	else
	  formatted << " " << it->str();
      if(badNums.str().empty())
	cout << entry.name << formatted.str() << endl;
      else
	cerr << "input error: " << entry.name
	     << " invalid number(s) " << badNums.str() << endl;
    }
}
