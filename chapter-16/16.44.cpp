// template <typename T> void g(T val);

// int i = 0; const int ci = i;

// a. g(i);
// T: int

// b. g(ci);
// T: const int;
// some one said here should be int and const is ignored.

// c. g(i * ci);
// T: int

// template <typename T> void g(const T& val);

// int i = 0; const int ci = i;

// a. g(i);
// T: int

// b. g(ci);
// T: int

// c. g(i * ci)
// T: int
