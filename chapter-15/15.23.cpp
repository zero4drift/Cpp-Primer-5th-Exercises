class Base
{
public:
  virtual int fcn();
};

class D1: public Base
{
public:
  int fcn() override;
  int fcn(int);
  virtual void f2();
};

class D2: public D1
{
public:
  int fcn(int);
  int fcn() override;
  void f2() override;
};

int main()
{
  Base bobj;
  D1 d1obj;
  D2 d2obj;
  Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
  // ...
  bp2->fcn();			// D1::fcn()
  // ...
  // others stay unchanged
}
