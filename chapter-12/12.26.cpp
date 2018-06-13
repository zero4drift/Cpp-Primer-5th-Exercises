#include <memory>
#include <string>
#include <iostream>

using std::allocator;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::size_t;
using std::stoul;

int main(int argc, char *argv[])
{
  if(argc != 2) return -1;
  size_t n = stoul(argv[1]);
  allocator<string> alloc;
  auto const p = alloc.allocate(n);
  string s;
  string *q = p;
  while(cin >> s && q != p + n)
    *q++ = s;
  const size_t size = q - p;
  // check
  cout << size << endl;
  while(q != p)
    alloc.destroy(--q);
  alloc.deallocate(p, n);
}
