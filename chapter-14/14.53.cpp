// Based on class type SmallInt defined in section 14.9.3;

// SmallInt sl;
// double d = s1 + 3.14;
// illegal, ambiguous calling;
// 1. member function: SmallInt operator+(const SmallInt &, const SmallInt &);
// 2. built-in + operator;

// fix:
// double d = static_cast<int>(s1) + 3.14;
