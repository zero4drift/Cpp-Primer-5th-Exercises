#include <string>

using std::string;

template <typename T> class Stack {};

void f1(Stack<char>);		// instantiation of Stack<char>, statement as 'Stack<char>' first appearance

class Exercise
{
  Stack<double> &rsd;		// instantiation of Stack<double>, its first appearance in context 
  Stack<int> si;		// instantiation of Stack<int>, its first appearance int context
};

int main()
{
  Stack<char> *sc;		// no instantiation, class instantiated before;
  f1(*sc);			// no instantiated, just call function
  int iObj = sizeof(Stack<string>); // instantiation, its first appearance in context
}
