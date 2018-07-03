struct If_Then_Else
{
  int operator()(int, int, int) const;
};

int If_Then_Else::operator()(int a, int b, int c) const
{
  if(a)
    return b;
  else
    return c;
}
