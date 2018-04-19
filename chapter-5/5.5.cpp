#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
  int grade;
  vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
  cout << "Please enter a grade: " << endl;
  cin >> grade;
  string lettergrade;
  if(grade < 60)
    lettergrade = scores[0];
  else
    {
      lettergrade = scores[(grade - 50) / 10];
      if(grade != 100)
	{
	  if(grade % 10 > 7)
	    lettergrade += "+";
	  else if(grade % 10 < 3)
	    lettergrade += "-";
	}
    }
  cout << lettergrade << endl;
}
