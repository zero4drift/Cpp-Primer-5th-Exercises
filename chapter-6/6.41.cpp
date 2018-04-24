// char *init(int ht, int wd = 80, char bckground = ' ');
// a: init(); illegal, the first parameter does not have a default argment, so when init is called a related argument must be placed to initialize this parameter.
// b: init(24, 10); legal.
// c: init(14, '*'); legal but not properly called, though the second argument as a char object could be implicitly converted to int type, this calling would run successfully, but it is against the original design purpose.
