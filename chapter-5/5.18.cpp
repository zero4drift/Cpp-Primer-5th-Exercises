#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  do
    {
      int v1, v2;		// requires a statement or a compound statement.
      cout << "Please Enter two numbers to sum:";
      if(cin >> v1 >> v2)
	cout << "Sum is : " << v1 + v2 <<endl;
    }
  while(cin);

  int ival = get_response();
  do
    {
      // statement that could modify ival
    }
  while(ival);

  // do
  //   {
  //     int ival = get_response();
  //   }
  // while(ival);              // variable used by condition statement must be defined outside of loop statement, same correctness as qustion b.
}
