// a: int calc(int, int);
// int calc(const int, const int); legal overload that this function name could be called with two const int type arguments

// b: int get();
// double get(); illegal, exactly the same as the first function except for the return type, it is forbidden in C++

// c: int *reset(int *);
// double *reset(doouble *); legal, overload that this function name could be called with one double* argument and returns a double* value. 
