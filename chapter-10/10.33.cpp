#include <string>
#include <iterator>
#include <fstream>

using std::string;
using std::istream_iterator;
using std::ostream_iterator;
using std::ifstream;
using std::ofstream;

void even_odd_f2f(const string &inf, const string &outf1, const string &outf2)
{
  ifstream ifs(inf);
  ofstream ofs1(outf1);
  ofstream ofs2(outf2);
  istream_iterator<int> in_iter(ifs), eof;
  ostream_iterator<int> out_iter1(ofs1, " "), out_iter2(ofs2, "\n");
  while(in_iter != eof)
    {
      (*in_iter % 2) ? out_iter1 = *in_iter : out_iter2 = *in_iter;
      ++in_iter;
    }
}

int main(int argc, char *argv[])
{
  if(argc != 4) return -1;
  even_odd_f2f(argv[1], argv[2], argv[3]);
}
