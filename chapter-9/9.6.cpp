#include <list>

using std::list;

int main()
{
  list<int> lst1;
  list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
  while(iter1 != iter2) continue; // iterator of list<int> does not support < operator(for that the elements whitin is not stored in sequence)
}
