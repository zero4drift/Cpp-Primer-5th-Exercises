#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string complete_name(string name, string prefix, string suffix)
{
  name.insert(0, " ");
  name.insert(0, prefix);
  name.insert(name.length(), " ");
  name.insert(name.length(), suffix);
  return name;
}

int main()
{
  string s = "Robert Jones";
  string result = complete_name(s, "Mr.", "Jr.");
  cout << result << endl;
}
