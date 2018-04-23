#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

void print_vector(vector<int>::iterator biter, vector<int>::iterator eiter)
{
  if(biter != eiter)
    {
      cout << *biter << endl;
      print_vector(++biter, eiter);
    }
}

int main()
{
  vector<int> iv = {1, 2, 3, 4, 5};
  print_vector(iv.begin(), iv.end());
}
