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
  (grade < 60) ? (lettergrade = scores[0]) : (lettergrade = scores[(grade - 50) / 10]);
  (grade != 100) ? ((grade % 10 > 7) ? (lettergrade += "+") : ((grade % 10 < 3) ? (lettergrade += "-") : lettergrade)) : lettergrade;
  cout << lettergrade << endl;
}
