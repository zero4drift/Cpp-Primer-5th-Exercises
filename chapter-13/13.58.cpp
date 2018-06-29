#include <vector>
#include <iostream>
#include  <algorithm>

using std::vector;
using std::cout;
using std::sort;
using std::endl;

class Foo
{
public:
  Foo sorted() &&;
  Foo sorted() const &;
private:
  vector<int> data;
};

// Foo Foo::sorted() const &
// {
//   cout << "Foo Foo::sorted() const &" << endl;
//   Foo ret(*this);
//   return ret.sorted();		// segment fault 
// }

Foo Foo::sorted() const &
{
  return Foo(*this).sorted();	// passed 
}

Foo Foo::sorted() &&
{
  sort(data.begin(), data.end());
  return *this;
}

int main()
{
  Foo f;
  f.sorted();
}
