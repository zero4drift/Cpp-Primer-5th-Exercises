// (a)
template <typename T, typename U, typename V> void f1(T, U, V);

// (b)
template <typename T> T f2(int &);

// (c)
template <typename T> T foo(T, unsigned int*);

// (d)
template <typename T> void f4(T, T);

// (e)
typedef char Ctype;
template <typename Ctype> Ctype f5(Ctype a);
