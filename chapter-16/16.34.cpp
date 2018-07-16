template <class T> int compare(const T &, const T &);

// a. compare("hi", "world");
// illegal;
// the function parameters have same type, and both are reference;
// and "hi" and "world" passed in as function arguments, the first's type is 'const char[3]', the second is 'const char[6]'
// T deduced from first function argument and second does not match.

// b. compare("bye", "dad");
// legal;
// same theory as mentioned in a:
// now T deduced from first function argument and second matches;
