#include <vector>

using std::vector;

class Example
{
public:
  static double rate;		// generally static data member should defined outside of class 
  static const int vecSize = 20;
  static vector<double> vec;	// same reason as before
};

double Example::rate = 6.5;
vector<double> Example::vec(vecSize);
