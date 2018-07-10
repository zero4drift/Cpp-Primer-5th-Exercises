#include "15.35.h"

int main()
{
  Query q = Query("fiery") & Query("bird") | Query("wind");
  cout << q;
}
