// Exercise should indicate that there is need to modify the header file contains class Query_base and AndQuery.

#include <iostream>
#include "Query.hpp"

using std::cout;
using std::endl;

int main()
{
  AndQuery aq = AndQuery(Query("hello"), Query("world")); 
  OrQuery oq = OrQuery(Query("hello"), Query("world"));
  Query_base *qb1 = &aq;
  Query_base *qb2 = &oq;
  AndQuery *pa1 = dynamic_cast<AndQuery*>(qb1);
  AndQuery *pa2 = dynamic_cast<AndQuery*>(qb2);
  if(pa1 && typeid(*pa1) == typeid(AndQuery))
    cout << "ok" << endl;
  if(pa2 && typeid(*pa2) == typeid(AndQuery))
    cout << "ok" << endl;
}
