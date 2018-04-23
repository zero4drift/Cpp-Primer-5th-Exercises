#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
  for(size_t index = 1; argv[index] != 0; ++index)
    cout << argv[index] << endl;
}
