int main()
{
  int ival = 1.01;		// right, precision loss
  int &rvall = 1.01;		// false, reference must be binded to an object
  int &rval2 = ival;		// right
  int &rval3;			// false, reference must be initialized
}
