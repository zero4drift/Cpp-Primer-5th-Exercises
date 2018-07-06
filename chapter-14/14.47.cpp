struct Integral
{
  operator const int();		// meaningless, for onr conversion operator should not define return type, this 'const' here is unspecified, it will be ignored by compiler.
  operator int() const;		// Not only non-const but also const Integral objects could call this one, Integral objects would be converted to int.
};

