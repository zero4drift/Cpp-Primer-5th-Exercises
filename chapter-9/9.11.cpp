#include <vector>

using std::vector;

int main()
{
  vector<int> iv1;		// empty
  vector<int> iv2 = {1, 2, 3, 4, 5}; // {1, 2, 3, 4, 5}
  vector<int> iv3 = iv2;	     // {1, 2, 3, 4, 5"
  vector<int> iv4(iv3.begin(), iv3.end()); // {1, 2, 3, 4, 5"
  vector<int> iv5(6);			   // {0, 0, 0, 0, 0, 0}
  vector<int> iv6(6, 1);		   // {1, 1, 1, 1, 1, 1}
}
