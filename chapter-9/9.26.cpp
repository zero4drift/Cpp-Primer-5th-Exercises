#include <vector>
#include <iterator>
#include <list>

using std::begin;
using std::end;
using std::vector;
using std::list;

int main()
{
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  vector<int> iv;
  list<int> il;
  auto ia_bg = begin(ia), ia_ed = end(ia);
  while(ia_bg != ia_ed)
    {
      iv.push_back(*ia_bg);
      il.push_back(*ia_bg);
      ++ia_bg;
    }
  auto it_iv = iv.begin();
  while(it_iv != iv.end())
    {
      if(*it_iv % 2 == 0)
	it_iv = iv.erase(it_iv);
      else
	++it_iv;
    }
  auto it_il = il.begin();
  while(it_il != il.end())
    {
      if(*it_il % 2)
	it_il= il.erase(it_il);
      else
	++it_il;
    }
}
