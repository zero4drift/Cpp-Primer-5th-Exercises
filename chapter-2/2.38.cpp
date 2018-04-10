int main()
{  
  int i = 0, &r = i;
  // same
  auto a = i;
  decltype(i) b = i;
  // different
  auto c = r;			// c int 
  decltype(r) d = r;		// d int&
}
