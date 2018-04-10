int main()
{
  r1 = v2;			// right, top-level const of v2 is not affected
  p1 = p2;			// false, low-level const of p2 is affected
  p2 = p1;			// right, no const is affected
  p1 = p3;			// false, low-level const of p3 is affected
  p2 = p3;			// right, no const is affedted
}
