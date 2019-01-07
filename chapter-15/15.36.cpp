#include "15.35.hpp"

int main()
{
  Query q = Query("fiery") & Query("bird") | Query("wind");
  cout << q;
}
