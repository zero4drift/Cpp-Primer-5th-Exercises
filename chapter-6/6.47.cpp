#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;
using std::cerr;

void print_vector(vector<int>::iterator biter, vector<int>::iterator eiter)
{
  if(biter != eiter)
    {
      #ifndef NDEBUG		// g++ -D NDEBUG 6.47.c would define NDEBUG and that when processing next statement would be skipped
      cerr << "The size of vector: " << eiter - biter << endl;
      #endif
      cout << *biter << endl;
      print_vector(++biter, eiter);
    }
}

int main()
{
  vector<int> iv = {1, 2, 3, 4, 5};
  print_vector(iv.begin(), iv.end());
}
