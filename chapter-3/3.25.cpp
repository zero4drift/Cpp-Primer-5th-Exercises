#include <vector>
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
  vector<unsigned> scores(11, 0);
  unsigned grade;
  while(cin >> grade)
    {
      if(grade <= 100)
	++(*(scores.begin() + (grade / 10)));
    }
  for(auto u : scores)
    cout << u << endl;
}
