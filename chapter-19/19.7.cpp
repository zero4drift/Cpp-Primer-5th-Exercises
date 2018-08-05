#include <stdexcept>
#include <iostream>
#include "Query.h"

using std::bad_cast;
using std::cout;
using std::endl;

int main()
{
  AndQuery aq = AndQuery(Query("hello"), Query("world")); 
  OrQuery oq = OrQuery(Query("hello"), Query("world"));
  Query_base &qb1 = aq;
  Query_base &qb2 = oq;
  try
    {
      AndQuery &pa1 = dynamic_cast<AndQuery&>(qb1);
      if(typeid(pa1) == typeid(AndQuery))
	cout << "ok" << endl;
    }
  catch(bad_cast)
    {
      cout << "fail" << endl;
    }
  
  try
    {
      AndQuery &pa2 = dynamic_cast<AndQuery&>(qb2);
      if(typeid(pa2) == typeid(AndQuery))
	cout << "ok" << endl;
    }
  catch(bad_cast)
    {
      cout << "fail" << endl;
    }
}
