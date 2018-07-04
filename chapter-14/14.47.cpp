struct Integral
{
  operator const int();		// only non-const Integral object could call this converion operator, and it would be converted to const int. 
  operator int() const;		// Not only non-const but also const Integral objects could call this one, Integral objects would be converted to int.
};
