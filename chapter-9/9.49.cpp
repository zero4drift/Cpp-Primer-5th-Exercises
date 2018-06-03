#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::string;

int main(int argc, char *argv[])
{
  if(argc != 2)
    {
      cerr << "Invalid arguments, need 2, now " << argc << endl;
      return -1;
    }
  ifstream ifs(argv[argc - 1]);
  if(!ifs)
    {
      cerr << "Invalid file name " << argv[argc - 1] << endl;
      return -1;
    }
  string ascender("bdfhtBDFHT");
  string descender("gpyGPY");
  string word, result;
  while(ifs >> word)
    {
      if(word.find_first_of(ascender) == string::npos &&
	 word.find_first_of(descender) == string::npos)
	if(word.size() > result.size())
	  result = word;
    }
  cout << result << endl;
}
