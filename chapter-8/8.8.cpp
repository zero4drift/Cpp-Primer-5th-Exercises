#include <fstream>
#include <iostream>
#include "Sales_data.hpp"

using std::ifstream;
using std::ofstream;
using std::endl;
using std::cerr;

int main(int argc, char *argv[])
{
  if(argc != 3)
    {
      cerr << "Incorrect command-line args"
	   << " Need 3 now " << argc << endl;  
      return -1;
    }
  ifstream input(argv[argc - 2]);
  ofstream output(argv[argc - 1], ofstream::app);
  Sales_data total;
  if(read(input, total))
    {
      Sales_data trans;
      while(read(input, trans))
	{
	  if(total.isbn() == trans.isbn())
	    total.combine(trans);
	  else
	    {
	      print(output, total) << endl;
	      total = trans;
	    }
	}
      print(output, total) << endl;
    }
  else
    cerr << "No data?" << endl;
}
