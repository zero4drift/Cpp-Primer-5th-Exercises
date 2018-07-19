// During template argument deduction:
// as for function template, compiler deduces the template argument from the passed in function arguments, instantiates a version of the function best matches the given call;
// if one function paramenter uses template type parameter, only const conversion and array-pointer & function-pointer conversion could be applied to corresponding passed in arguments;
// usually compiler does not apply conversion to arguments, but instantiates a new template instance based on the type of arguments.
