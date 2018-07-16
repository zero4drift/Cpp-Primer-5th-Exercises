template <typename T> void g(T&& val);

int i = 0; const int ci = i;

// a. g(i);
// T: int&
// val: int&

// b. g(ci);
// T: const int&
// val: const int&

// c. g(i * ci);
// T: int
// val: int&&
