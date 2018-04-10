int main()
{
  const int buf;		// const variable must be initialized
  int cnt = 0;			// right
  const int sz = cnt;		// right, iust copy the value
  ++cnt, ++sz;			// first is right, second is false, could not change a constant value
}
