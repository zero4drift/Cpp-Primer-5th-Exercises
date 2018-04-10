int main()
{
  int a = 3, b = 4;
  decltype(a) c = a;		// c int, 3
  decltype((a = b)) d = a;	// d int&, bind to a, 3
}
