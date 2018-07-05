struct LongDouble
{
  LongDouble(double = 0.0);
  operator double();
  operator float();
};

LongDouble ldObj;
int ex1 = ldObj;		// illegal
// could call ldObj.double() and then convert double to int;
// could call ldObj.float() and then convert float to int;
// both are at same level, this expression introduces ambiguous call.
float ex2 = ldObj;		// legal
// call ldObj.float() and no more built-in type conversion
// best match. 
