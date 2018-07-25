#include <regex>
#include <string>
#include <iostream>

using std::regex;
using std::regex_error;
using std::cmatch;
using std::regex_search;
using std::string;
using std::cout;
using std::endl;

int main()
{
  try
    {
      // regex r("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase); // error code 4; 
      regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
      cmatch results;		// compiler error if using smatch;
      if(regex_search("myfile.cc", results, r))
      	cout << results.str() << endl;
    }
  catch(regex_error e)
    {
      cout << e.what() << "\ncode: " << e.code() << endl;
    }
}
