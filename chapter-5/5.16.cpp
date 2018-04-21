#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
  int i;
  // while(cin >> i)
  //   cout << i << endl;                 // while better in a loop whose loop cnt is unclear
  for(; cin >> i; )
    cout <<i << endl;

  vector<int> iv = {1, 2, 3, 4, 5, 6};
  auto length = iv.size();
  decltype(length) index = 0;
  while(index != iv.size())
    {
      cout << iv[index];
      ++index;
    }
  for(decltype(iv.size()) index = 0; index != iv.size(); ++index) // for better in a loop whose loop cnt is clear
    cout << iv[index];
  // which is preffered based on certain situation
}
