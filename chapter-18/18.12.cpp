// See chapter15.h, chapter15.cpp, chapter10.h and chapter15.cpp.

#include <fstream>
#include <iostream>
#include "chapter10.hpp"
#include "chapter15.hpp"

using std::ifstream;
using std::cout;
using std::string;

int main(int argc, char *argv[])
{
  ifstream ifs(argv[1]);
  chapter10::TextQuery tq(ifs);
  chapter15::Query q = chapter15::Query("fiery") & chapter15::Query("bird") | chapter15::Query("wind");
  cout << q << endl;
  auto result = q.eval(tq);
  print(cout, result);
}
