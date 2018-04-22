// a: type of function unmatchs its return value
// string f()
// {
//   string s;
//   // ...
//   return s;
// }

// b: type of return value not specified
// int f2(int i) { /* ... */ }

// c: missing left '{', parameters with same name
// int calc(int v1, int v2) { /* ... */ }

// d: missing a pair of curly braces(the function body must be a block)
// double square(double x) {return x * x;}
