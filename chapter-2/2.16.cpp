int main()
{
  int i, &r1 = i;
  double d = 0, &r2 = d;
  r2 = 3.14159;			// right
  r2 = r1;			// right
  i = r2;			// right, maybe precision loss
  r1 = d;			// right, maybe precision loss
}
