int main()
{
  int i = -1, &r = 0;		// false, reference must be binded to an object
  int *const p2 = &i2;		// right
  const int i = -1, &r = 0;	// right, reference to constant could be binded to literal
  const int *const p3 = &i2;	// right, whether i2 is constant or not has no effect
  const int *p1 = &i2;		// right
  const int &const_r2;		// false, reference must be initialized
  const int i2 = i, &r = i;	// right
}
