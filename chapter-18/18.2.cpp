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
  
  // suspend the process of current function;
  // if there is a matched catch expression in current function
  // execute this expression and program processing from the point
  // which is just after the last catch expression of matched catch
  // expression group;
  // if not so,
  // leave and go on searching for matched catch in caller function
  // local objects defined in this function body would be destructed.
}
