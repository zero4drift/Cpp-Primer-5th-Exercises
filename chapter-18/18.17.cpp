namespace Exercise
{
  int ivar = 0;
  double dvar = 0;
  const int limit = 1000;
}

int ivar = 0;
// using Exercise::ivar;    // name conflict
// using Exercise::dvar;
// using Exercise::limit;

// using namespace Exercise;

void manip()
{
  // using Exercise::ivar;
  // using Exercise::dvar;
  // using Exercise::limit;

  // using namespace Exercise;
  
  double dvar = 3.1416;
  // would bring name conflict if there are using declarations of all members of namespace Exercise inside manip;
  int lobj = limit + 1;
  ++ivar;			// using directive: ambiguous: which ivar?
  ++::ivar;
}
