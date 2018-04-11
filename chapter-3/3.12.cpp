#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
  vector<vector<int>> ivec;	// legal, a vector object whose element is a vector object whose element is int object, first the whole vector object is empty
  vector<string> svec = ivec;	// illegal, types not match
  vector<string> svec1(10, "null"); // legal, a vector object whose elements are 10 string objects with value "null"
}
