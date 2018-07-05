// LongDouble operator+(LongDouble &, double);
// SamllInt si;
// LongDouble ld;

// ld = si + ld;
// candidates:
// 1. LongDouble operator+(LongDouble &, double);
// 2. member function: SmallInt operator+(const SmallInt &, const SmallInt &);
// 3. built-in + operator; ambiguous.
// none of these matchs.

// ld = ld + si;
// candidates:
// 1. LongDouble operator+(LongDouble &, double); si converted to int by class type conversion, and then int converted to double by built-in type conversion.
// 2. member function: LongDouble operator+(const SmallInt &); si const conversion.
// 3. built-in + operator; ambiguous
// candidate 2 is applied.
