int main()
{
  char cval;
  int ival;
  unsigned int ui;
  float fval;
  double dval;
  cval = 'a' + 3;		// implicit conversion, char -> int, int -> char
  fval = ui - ival * 1.0;	// ~, int -> double, unsigned int -> double, double -> float
  dval = ui * fval;		// ~, unsigned int -> float, float -> double
  cval = ival + fval + dval;	// ~, int -> float, float -> double, double -> char
}
