template <typename T> T calc(T, int);
template <typename T> T fcn(T, T);

double d; float f; char c;

// a. calc(c, 'c');
// legal, T: char;

// b. calc(d, f);
// legal, T: double

// c. fcn(c, 'c');
// legal, T: char

// d. fcn(d, f);
// illegal, function template fcn's parameter list accepts two paramters with same type which is template type parameter, now for first time template type parameter deduced from function argument is double, second time float, not match.a
