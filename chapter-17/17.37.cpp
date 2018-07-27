// Program processing ends when encounters a line whose length is larger than specified array size.
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;

int main(int argc, char *argv[])
{
  ifstream ifs(argv[1]);
  while(ifs)
    {
      char sample[30];
      ifs.getline(sample, 30, '\n');
      cout.write(sample, 30) << endl;
    }
}
