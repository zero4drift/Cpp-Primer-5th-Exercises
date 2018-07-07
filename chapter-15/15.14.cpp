#include <iostream>
#include "15.13.cpp"

using std::cout;

int main()
{
  base bobj;
  derived dobj;
  base *bp1 = &bobj;
  base *bp2 = &dobj;
  base &br1 = bobj;
  base &br2 = dobj;

  bobj.print(cout);		// base::print
  dobj.print(cout);		// derived::print
  bp1->name();			// base::name
  bp2->name();			// base::name
  br1.print(cout); 		// base::print
  br2.print(cout);		// derived::print
}
