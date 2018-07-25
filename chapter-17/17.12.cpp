#include <bitset>

using std::bitset;

template <size_t n>
void update_results(bitset<n> results, size_t index, bool result)
{
  results.set(index, result);
}
