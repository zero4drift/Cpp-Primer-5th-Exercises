int main()
{
  unsigned buf_size = 1024;
  int ia[buf_size];		// illegal, buf_size is not const expr
  int ia[4 * 7 - 14];		// legal, that index is const expr;
  int ia[txt_size()];		// illegal, index part is not a constexpr function
  char st[11] = "fundermental";	// space of array is not enough
}
