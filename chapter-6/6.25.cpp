#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
  if(argc != 3) return -1;
  string s1 = argv[1];
  string s2 = argv[2];
  cout << s1 + s2 << endl;
}
