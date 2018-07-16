// max(int i, double d);
// illegal;
// for max is a function template which only accepts one template type parameter;
// assumes this template looks like this: template <typename T> max(T a, T b);
// if call this max like the first line above, template type parameter T deduced from the first passed in argument would be int, and after second deduction T would be double;
// not match.
