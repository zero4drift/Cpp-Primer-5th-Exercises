#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::back_inserter;
using std::istream_iterator;
using std::ostream_iterator;
using std::sort;
using std::copy;
using std::unique_copy;

int main()
{
  istream_iterator<int> in_iter(cin), eof;
  ostream_iterator<int> out_iter(cout, "\n");
  vector<int> vi;
  copy(in_iter, eof, back_inserter(vi));
  sort(vi.begin(), vi.end());
  unique_copy(vi.begin(), vi.end(), out_iter);
}
