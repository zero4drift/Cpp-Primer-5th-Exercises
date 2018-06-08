#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::find;

int main()
{
  string word;
  vector<string> words;
  while(cin >> word)
    {
      auto iter = find(words.begin(), words.end(), word);
      if(iter == words.end())
	words.push_back(word); 
    }
  cout << "Unique words among inputs: " << endl;
  for(const auto &s : words) cout << s << endl;
}

// if using type set, program would be much easier, the type itself determines that there is no duplicated elements within, so just push word to set and omit checkwork would do the job for us.
