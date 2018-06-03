#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string complete_name(string name, string prefix, string suffix)
{
  auto beg = name.begin();
  beg = name.insert(beg, 1, ' ');
  name.insert(beg, prefix.begin(), prefix.end());
  name.append(" ");
  name.append(suffix);
  return name;
}

int main()
{
  string s = "Robert Jones";
  string result = complete_name(s, "Mr.", "Jr.");
  cout << result << endl;
}
