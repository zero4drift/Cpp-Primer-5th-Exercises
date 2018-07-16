template <typename T> void f1(T, T);
template <typename T1, typename T2> void f2(T1, T2);

int i = 0, j = 42, *p1 = &i, *p2 = &j;
const int *cp1 = &i, *cp2 = &j;

// a. f1(p1, p2);
// T of first template deduced as int*, instantiates a template instance: f1(int*, int*);

// b. f2(p1, p2);
// T1 of second template deduced as int*, T2 as int*, new instance: f2(int*, int*);

// c. f1(cp1, cp2);
// T of first template deduced as const int*, nes instance: f1(const int*, const int*)

// d. f2(cp1, cp2);
// T1 of second template deduced as const int*, second as const int*, new instance: f2(const int*, const int*)

// e. f1(p1, cp2);
// illegal;
// T deduced from first argument of f1 is int*, deduced from seond argument is const int*, not match

// f. f2(p1, cp1);
// T1 of second template deduced as int*, T2 of second template deduced as const int*, new instance: f2(int*, const int*)
