#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;

int main(int argc, char *argv[])
{
  char sample[30];
  ifstream ifs(argv[1]);
  while(ifs)
    {
      ifs.getline(sample, 30, ' ');
      cout << sample;
    }
}
