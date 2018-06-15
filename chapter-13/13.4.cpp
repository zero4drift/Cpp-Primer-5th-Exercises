Point global;
Point foo_var(Point arg)	// argument passed in would call copy constructor 
{
  Point local = arg, *heap = new Point(global); // the fisrst as copy initialization would call copy constructor
  *heap = local;				// copy-assignment operator
  Point pa[4] = {local, *heap};			// use curly braced list to initialize array would call copy constructor
  return *heap;					// return an object, and the return type of this function is not reference, then it calls copy constructor
}
