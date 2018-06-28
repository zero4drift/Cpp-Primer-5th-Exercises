// See HasPtr.h.

// The efficiency of copy-assgnment operator of HasPtr class type is not good enough, for that there is a copy constructor called when argument passed in, and the exchanging of value within function body may be unnecessary.

// The new move-assignment operator takes control of the resources owned by another source object, and makes sure that object in a valid and destruction-safe state.

// The copy-swap operator implements assignment by value exchanging, finally the data member ps points to a new allocated string, which is a copy of string object pointed by right operand's data member ps, the right operand stays unchanged.
