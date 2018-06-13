#include <string>
#include <iterator>
#include <cstring>

using std::string;
using std::begin;
using std::end;
using std::strcat;
using std::strcpy;
using std::size_t;

int main()
{
  /* using unique_ptr to point to the dynamic array
     would make this program much easier */
  // char *
  char *p = new char[20]();
  const char c[] = "hello", d[] = "world";
  strcpy(p, c);
  strcat(p, " ");
  strcat(p, d);
  delete [] p;
  // string
  string *s = new string[2]();
  string s1("hello");
  string s2("world");
  *s = s1;
  *(s + 1) = s2;
  delete [] s;
}
