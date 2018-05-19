#include <string>

using std::string;

typedef string Type;
Type initVal();			// Type declared before

class Exercise
{
public:
  typedef double Type;
  Type setVal(Type);		// Type declared in class
  Type initVal();		// same
private:
  int val;
};

Exercise::Type Exercise::setVal(Type parm) // type member Type of class Exercise
{
  val = parm + initVal();
  return val;
}

// and Exercise::initVal() should be defined
