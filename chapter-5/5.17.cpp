#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int main()
{
  vector<int> iv1 = {1, 2, 3, 4}, iv2 = {1, 2, 3, 4, 5, 6};
  bool isPrefix = true;

  for(decltype(iv1.size()) index = 0; index != iv1.size() && index != iv2.size(); ++index)
    if(iv1[index] != iv2[index])
      {
	isPrefix = false;
	break;
      }

  cout << "Is one vector as another vector's prefix? " << isPrefix << endl;
}
