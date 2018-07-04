#include <map>
#include <functional>
#include <string>
#include <iostream>

using std::map;
using std::function;
using std::string;
using std::cout;
using std::endl;

int add(int i, int j) {return i + j;}
auto mod = [](int i, int j) {return i % j;};
struct divide
{
  int operator()(int denominator, int divisor)
  {return denominator / divisor;}
};

map<string, function<int(int, int)>> binops =
  {
    {"+", add},
    {"-", std::minus<int>()},
    {"/", divide()},
    {"*", [](int i, int j) {return i * j;}},
    {"%", mod}
  };

int main()
{
  cout << binops["-"](3, 4) << endl;
}
