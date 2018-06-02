// infinite loop, always insert a copy at the front of the fitst encountered odd number.

#include <vector>

using std::vector;

int main()
{
  vector<int> vi = {1, 2, 3, 4, 5};
  auto iter = vi.begin();
  while(iter != vi.end())
    {
      if(*iter % 2)
	iter = vi.insert(iter, *iter);
      ++iter;
    }
}
