#include <bitset>
#include <iostream>

using std::bitset;

template <size_t n>
void update_results(bitset<n> &results, size_t index, bool result)
{
  results.set(index, result);
}

int main()
{
  bitset<10> right_answers(0b0111000101);
  bitset<10> results;
  update_results(results, 0, true);
  update_results(results, 2, true);
  update_results(results, 6, true);
  update_results(results, 7, true);
  update_results(results, 8, true);
  unsigned score = 0;
  for(size_t n = 0; n != results.size(); ++n)
    if(right_answers[n] == results[n])
      ++score;
  std::cout << score << std::endl;
}
