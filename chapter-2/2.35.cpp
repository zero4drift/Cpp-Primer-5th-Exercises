int main()
{
  const int i = 42;
  auto j = i;			// j int, 4
  const auto &k = i;		// k const int&, bind to i, 42
  auto *p = &i;			// p const int*, points to i
  const auto j2 = i, &k2 = i;   // j2 const int, 42, k2 const int&, bind to i, 42
}
