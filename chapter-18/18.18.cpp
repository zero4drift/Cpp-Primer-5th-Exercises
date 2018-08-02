// if mem1 data member of class T is a string object, using the specified version swap for string type;
// first searching fot suitable function in current scope, then check outer scopes, finally, due to the argumenta is of string class type, check the namespace std which includes the definition of string;
// found the specified version swap in namespace std for string type.

// if its type is int, using the swap version defined in namespace std;
// as descrived before, and because built-in type has no spedified swap version but the std::swap, the searching is completed in current scope.
