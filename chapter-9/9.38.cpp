#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main()
{
  vector<int> vi;
  cout << "size " << vi.size() << " "
       << "capacity " << vi.capacity() << endl;
  vi.push_back(1);
  cout << "size " << vi.size() << " "
       << "capacity " << vi.capacity() << endl;
  vi.push_back(2);
  cout << "size " << vi.size() << " "
       << "capacity " << vi.capacity() << endl;
  vi.push_back(3);
  cout << "size " << vi.size() << " "
       << "capacity " << vi.capacity() << endl;
  vi.push_back(4);
  vi.push_back(5);
  cout << "size " << vi.size() << " "
       << "capacity " << vi.capacity() << endl;
}
