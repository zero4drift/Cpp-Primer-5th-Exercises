int main()
{
  i = ic;			// right, just copy the value
  p1 = p3;			// false, if passed the const object pointed by p3 could be modified through p1
  p1 = &ic;			// false, same reason as the former one
  p3 = &ic;			// false, const pointer could not be modified
  p2 = p1;			// false, same reason as the former one
  ic = *p3;			// false, const int object could not be modified
}
