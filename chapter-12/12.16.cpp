#include <memory>

using std::unique_ptr;

int main()
{
  unique_ptr<int> p(new int(1));
  unique_ptr<int> q(p);		// unique_ptr does not support copy
  unique_ptr<int> x;		// unique_ptr does not support assignment
  x = p;
}
