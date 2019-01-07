// using find, program is really complex
// easier and simpler if using find_if
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <numeric>
#include "Sales_item.hpp"

using std::vector;
using std::copy;
using std::sort;
using std::find_if;
using std::back_inserter;
using std::istream_iterator;
using std::ostream_iterator;
using std::cin;
using std::cout;
using std::accumulate;

bool compareIsbn(Sales_item &s1, Sales_item &s2)
{
  return s1.isbn() < s2.isbn();
}

int main()
{
  vector<Sales_item> vsa;
  istream_iterator<Sales_item> in_iter(cin), eof;
  ostream_iterator<Sales_item> out_iter(cout);
  copy(in_iter, eof, back_inserter(vsa));
  sort(vsa.begin(), vsa.end(), compareIsbn);
  auto iter = vsa.cbegin();
  while(iter != vsa.cend())
    {
      Sales_item total;
      auto found = vsa.cend();
      auto temp = found;
      auto beg = iter;
      do
	{
	  ++iter;
	  temp = found;
	}
      while(iter != vsa.cend() && (found = find(iter, vsa.cend(), *beg)) != vsa.cend())
	if(temp == vsa.cend()) cout << *beg << endl;
	else cout << accumulate(beg, temp + 1, total) << endl;
    }
}
