// Chinese translation verseion of this exercise is ambiguous
// Guess that function should return a iterator

#include <vector>

using std::vector;
using vit = vector<int>::iterator;

vit find_i(vit begin, vit end, int i)
{
  while(begin != end && begin < end)
    {
      if(*begin == i) return begin;
      else ++begin;
    }
  return end;
}
