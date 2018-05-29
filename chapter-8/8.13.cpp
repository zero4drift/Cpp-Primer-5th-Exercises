#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

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

struct PersonInfo
{
  string name;
  vector<string> phones;
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
      while(record >> word)
	info.phones.push_back(word);
      people.push_back(info);
      record.clear();
    }

  for(const auto &entry : people)
    {
      ostringstream formatted, badNums;
      for(const auto &nums : entry.phones)
	{
	  if(!valid(nums))
	    badNums << " " << nums;
	  else
	    formatted << " " << format(nums);
	}
      if(badNums.str().empty())
	cout << entry.name << " "
	   << formatted.str() << endl;
      else
	cerr << "input error: " << entry.name
	     << " invalid number(s) " << badNums.str() << endl;
    }
}
