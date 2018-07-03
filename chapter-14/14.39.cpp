#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::string;
using std::ifstream;
using std::count_if;
using std::cerr;
using std::cout;
using std::endl;
using std::istream_iterator;

class EqLength
{
  size_t length = 0;
public:
  EqLength() = default;
  EqLength(size_t n): length(n) {}
  bool operator()(const string &) const;
};

bool EqLength::operator()(const string &s) const
{
  return s.size() == length;
}

class GeLength
{
  size_t length = 0;
public:
  GeLength() = default;
  GeLength(size_t n): length(n) {}
  bool operator()(const string &) const;
};

bool GeLength::operator()(const string &s) const
{
  return s.size() >= length;
}

int main(int argc, char *argv[])
{
  if(argc != 2)
    cerr << "False command-line arguments, expects "
	 << argc << endl;
  ifstream ifs(argv[1]);
  istream_iterator<string> beg(ifs);
  istream_iterator<string> eof;
  for(size_t l = 1; l < 10; ++l)
    {
      cout << "Length " << l <<  count_if(beg, eof, EqLength(l)) << endl;
    }
  cout << "Length not smaller than 10 " << count_if(beg, eof, GeLength(10)) << endl;
}
