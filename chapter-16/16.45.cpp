#include <vector>

using std::vector;

template <typename T> void g(T&& val) {vector<T> v;}

// call g with a literal constant of 42;
// T: int
// val: int&&
// initialize a empty vector with element type as int within instantiated function body.

// call g with a variable of type int;
// T: int&
// val: int
// vector<int&> is not legal.
