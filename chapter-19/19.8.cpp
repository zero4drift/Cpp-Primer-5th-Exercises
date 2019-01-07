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
  if(typeid(*qb1) == typeid(*qb2))
    cout << "equal" << endl;
  if(typeid(*qb1) == typeid(AndQuery) || typeid(*qb2) == typeid(AndQuery))
    cout << "AndQuery ok" << endl;
}
