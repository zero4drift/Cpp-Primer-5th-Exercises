namespace primerLib
{
  void compute();		// 1
  void compute(const void *);	// 2
}

using primerLib::compute;
void compute(int);		// 3
void compute(double, double = 3.4); // 4
void compute(char *, char * = 0);   // 5

void f()
{
  compute(0);
}

// first question:
// finally call version 3;
// candidate functions:
// 1
// 2
// 3
// 4
// 5

// workable functions:
// 2, literal constant 0 converted to const void *
// 3, match
// 4, int converted to double
// 5, literal constant 0 conveted to char *;

// second question:
// hide the function declarations with same name in outer scope;
// finally call version 2;
// candidate functions:
// 1
// 2

// workable functions:
// 2, literal constant 0 converted to const void *
