#include <list>
#include <vector>

using std::list;
using std::vector;

int main()
{
  list<int> lst_i = {1, 2, 3, 4, 5};
  vector<double> vec_d1(lst_i.begin(), lst_i.end());
  vector<int> vec_i= {1, 2, 3, 4, 5};
  vector<double> vec_d2(vec_i.begin(), vec_i.end());
}
