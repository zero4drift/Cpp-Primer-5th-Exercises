// (a)
template <typename T, typename U, typename V> void f1(T, U, V);

// (b)
template <typename T> T f2(T &);

// (c)
template <typename T> inline T foo(T, unsigned int*);

// (d)
template <typename T> void f4(T, T);

// (e)
typedef char Ctype;
// template declaration below hides this typedef
template <typename Ctype> Ctype f5(Ctype a);
