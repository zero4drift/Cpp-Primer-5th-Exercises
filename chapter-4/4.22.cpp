#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
  unsigned grade;
  cout << "Please enter a grade: " << endl;
  cin >> grade;
  string finalgrade;
  // that's simpler and better
  // finalgrade = (grade > 90) ? "high pass"
  //   : (grade > 60 && grade < 75) ? "low pass"
  //   : (grade < 60) ? "fail" : "pass";
  if(grade > 90) finalgrade = "high pass";
  else
    {
      if(grade > 60 && grade < 75) finalgrade = "low pass";
      else
	{
	  if(grade < 60) finalgrade = "fail";
	  else finalgrade = "pass";
	}
    }
  cout << finalgrade << endl;
}
