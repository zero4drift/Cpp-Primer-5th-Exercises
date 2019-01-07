#include "HasPtr.hpp"

int main()
{
  HasPtr h("helloworld");
  HasPtr h2 = h;
  HasPtr h3 = std::move(h2);
  h2 = h;
  h2 = std::move(h3);
  // if the original copy-assignment operator stay unchanged
  // compiler warns:
  // ambiguous overload for 'operator=' (operand types are 'HasPtr'
  // and 'std::remove_reference<HasPtr&>::type {aka HasPtr}')
}
