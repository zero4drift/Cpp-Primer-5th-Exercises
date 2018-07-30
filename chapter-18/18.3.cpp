// 1. associated try-catch expression inside function where exception occurs;
// 2. associated try-catch expression placed in caller function.
#include <vector>
#include <fstream>

using std::vector;
using std::ifstream;

void exercise(int *b, int *e)
{
  vector<int> v(b, e);
  int *p = new int[v.size()];
  ifstream in("this");
  // there exception occurs

  // 1.
  // try{...}
  // catch(exception){...}
}

void caller_exercise()
{
  // 2.
  // try{...exercise(...)...}
  // catch(exception){...}
}
