template <typename T> void f(T);
template <typename T> void f(const T*);
template <typename T> void g(T);
template <typename T> void g(T*);

int i = 42, *p = &i;
const int ci = 0, *p2 = &ci;

// g(42);
// call the instance of the third template: void g(int);

// g(p);
// call the instance of the fourth template: void g(int*);

// g(ci);
// call the instance of the third template: void g(const int);

// g(p2);
// call the instance of the fourth template: void g(const int*);

// f(42);
// call the instance of the first template: void f(int);

// f(p);
// call the instance of the first template: void f(int*);

// f(ci);
// call the instance of the first template: void f(const int);

// f(p2);
// call the instance of the second template: void f(const int*);
