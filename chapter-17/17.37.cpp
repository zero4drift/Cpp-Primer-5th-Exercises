// Program processing ends when encounters a line whose length is larger than specified array size;
// while if the size of array is set really large, there would be garbleds in outpus.
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;

int main(int argc, char *argv[])
{
  char sample[250];
  ifstream ifs(argv[1]);
  while(ifs)
    {
      ifs.getline(sample, 250, '\n');
      cout << sample << endl;
    }
}
