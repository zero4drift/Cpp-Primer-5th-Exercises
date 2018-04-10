int main()
{
  const int v2 = 0;		// top const
  int v1 = v2;
  int *p1 = &v1, &r1 = v1;
  const int *p2 = &v2, *const p3 = &i, &r2 = v2; // p2 low const, p3 top low const, r2 low const
}
