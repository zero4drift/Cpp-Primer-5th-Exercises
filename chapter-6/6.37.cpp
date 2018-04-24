#include <string>

using std::string;

using stringArray = string[10];

stringArray& func1();

auto func2() -> string(&)[10];	// it is better, easy to use and understand

string array[10];

decltype(array) &func3();
