int main()
{
  int a = 3, b = 4;
  decltype(a) c = a;		// c int, 3
  decltype((b)) d = a;		// d int&, 3
  ++c;				// 4
  ++d;				// 4
}
