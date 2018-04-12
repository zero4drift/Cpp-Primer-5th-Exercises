#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
  int ia[5] = {1, 2, 3, 4, 5};
  int ib[5] = {1, 2, 3, 4, 5};
  vector<int> va = {1, 2, 3, 4, 5};
  vector<int> vb = {1, 2, 3, 4, 5};
  auto ia_length = end(ia) - begin(ia);
  auto ib_length = end(ib) - begin(ib);
  if(ia_length != ib_length)
      cout << "array a not equals to array b" << endl;
  else
    {
      for(decltype(ia_length) index = 0; index < ia_length; ++index)
	{
	  if(ia[index] != ib[index])
	    {
	      cout << "array a not equals to array b" << endl;
	      break;
	    }
	}
    }
  // vector compare
  if(va != vb) cout << "vector a not equals to vector b" << endl;
}
