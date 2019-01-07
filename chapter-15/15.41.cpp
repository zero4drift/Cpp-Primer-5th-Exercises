#include <fstream>
#include <iostream>
#include "15.41.hpp"
#include "TextQuery.hpp"

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
