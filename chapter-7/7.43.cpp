class NoDefault
{
  int im;
public:
  NoDefault(int i): im(i) {}
};

class C
{
  NoDefault n_member;
public:
  C(int i): n_member(NoDefault(i)) {}
  C(): C(0) {}
};
