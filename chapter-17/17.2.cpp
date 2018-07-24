#include <tuple>
#include <vector>
#include <string>
#include <utility>

using std::tuple;
using std::vector;
using std::string;
using std::pair;

int main()
{
  tuple<string, vector<string>, pair<string, int>> ti("hello", {"hello", "world"}, {"answer", 42});
}
