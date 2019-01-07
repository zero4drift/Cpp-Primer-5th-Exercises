// implement (a)
// modify TextQuery.h
// see TextQuery-1542.h

#include <fstream>
#include <iostream>
#include "15.42.hpp"
#include "TextQuery-1542.hpp"

using std::ifstream;
using std::cout;
using std::string;

int main(int argc, char *argv[])
{
  ifstream ifs(argv[1]);
  TextQuery tq(ifs);
  Query q = Query("fiery") & Query("bird") | Query("wind");
  cout << q << endl;
  auto result = q.eval(tq);
  print(cout, result);
}
