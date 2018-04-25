#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
  return (ctr > 1) ? word + ending : word;
}

int main()
{
  string s1 = "success";
  string s2 = "failure";
  cout << make_plural(1, s1) << endl;
  cout << make_plural(1, s2) << endl;
  cout << make_plural(2, s1, "es") << endl;
  cout << make_plural(2, s2) << endl;
}
