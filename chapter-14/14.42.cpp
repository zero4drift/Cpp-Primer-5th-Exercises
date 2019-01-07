#include <functional>
#include <string>

using std::bind;
using std::greater;
using std::not_equal_to;
using std::multiplies;
using std::placeholders::_1;
using std::string;

int main()
{
  auto greater1024 = bind(greater<int>(), _1, 1024);
  auto not_equal_to_pooh = bind(not_equal_to<string>(), _1, "po.hpp");
  auto multiplies_2 = bind(multiplies<int>(), _1, 2);
}
