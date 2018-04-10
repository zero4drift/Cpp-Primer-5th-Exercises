int main()
{
  int i = 0;
  double* dp = &i;		// false, pointer and its target's type must match
  int *ip = i;			// false, directly assign a variable to a pointer
  int *p = &i;			// right
}
