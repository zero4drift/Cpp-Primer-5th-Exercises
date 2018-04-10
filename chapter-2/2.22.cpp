int main()
{
  int i = 4;
  int *p = &i;
  if(p) return 0;			// if p not a nullptr
  if(*p) return 0;			// if p points to a value which converted to bool whose value is true;
}
