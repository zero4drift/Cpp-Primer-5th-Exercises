#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
  int i1, i2;
  cout << "Please enter two integer numbers: ";
  while(cin >> i1 >> i2)
  {
    try
      {
	if(!i2)
	  throw runtime_error("ERROR! divided by 0!");
	cout << i1 / i2 << endl;
      }
    catch(runtime_error e)
      {
	cout << e.what()
	     << "\nTry again? Enter y or n" << endl;
	char c;
	cin >> c;
	if(!cin || c == 'n')
	  break;
      }
  }
}
