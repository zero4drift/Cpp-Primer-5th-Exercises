int main()
{
  int i, *const cp;		// false, const pointer must be initialized
  int *p1, *const p2;		// false, same reason as before
  const int ic, &r = ic;	// false, const int object must be initialized
  const int *const p3;		// false, ...
  const int *p;			// right, defines a pointer which points to const int object
}
