#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <iostream>

using std::vector;
using std::string;
using std::istream_iterator;
using std::ifstream;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
  if(argc != 2) return -1;
  ifstream ifs(argv[1]);
  istream_iterator<string> ifs_iter(ifs), eof;
  vector<string> vs(ifs_iter, eof);
  for(const auto &s : vs)
    cout << s << endl;
}
