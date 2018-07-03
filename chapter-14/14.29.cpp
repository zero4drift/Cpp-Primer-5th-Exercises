// The overload ++ & -- operators as member functions could not be defined as const member functions,
// because within these functions'body, the caller StrBlobPtr object would be modified, and const object could not be modified.
