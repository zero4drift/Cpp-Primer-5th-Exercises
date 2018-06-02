#include <vector>

using std::vector;

bool find_i(vector<int>::iterator begin, vector<int>::iterator end, int i)
{
  while(begin != end && begin < end)
    {
      if(*begin == i) return true;
      else ++begin;
    }
  return false;
}
