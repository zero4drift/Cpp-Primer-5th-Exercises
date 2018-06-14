// illegal
// built-in type object defined inside code block but without value initialization, its value would be undefined;
// and p will convert to a bool, the dynamic memory allocated has no chance to be freed.
