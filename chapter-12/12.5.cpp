// The constructor function StrBlob::StrBlob(initializer_list<string> il) is not explicit;
// advantage: elements surrounded by curly braces could be implicitly transformmed to initializer_list object, for example, no need to explicitly construct a initialize_list<string> object to pass it to the constructor function; this feature allows copy initialization with different types.
// disadvantage: the explicit way is more strict, for implicit transformer may pass in an invalid argument which does not meet the requirement of parameter, introduces an error by carelessness; this feature only allows direct initialization.
