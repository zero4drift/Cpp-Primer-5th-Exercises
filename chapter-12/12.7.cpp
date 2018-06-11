#include <vector>
#include <memory>
#include <iostream>

using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::cin;
using std::cout;
using std::endl;

shared_ptr<vector<int>> new_vector()
{
  return make_shared<vector<int>>();
}

void read_vector(shared_ptr<vector<int>> p)
{
  int i;
  while(cin >> i)
    p->push_back(i);
}

void print_vector(shared_ptr<vector<int>> p)
{
  for(const auto &i : *p)
    cout << i << endl;
}

int main()
{
  auto p = new_vector();
  read_vector(p);
  print_vector(p);
}
