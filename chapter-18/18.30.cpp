class Class
{};

class Base
{
  int i = 0;
public:
  Base() = default;
  Base(int j): i(j) {}
  Base(const Base &b): i(b.i) {}
};

class D1: virtual public Base
{
public:
  D1(): Base() {}
  D1(int j): Base(j) {}
  D1(const D1 &d): Base(d) {}
};

class D2: virtual public Base
{
public:
  D2(): Base() {}
  D2(int j): Base(j) {}
  D2(const D2 &d): Base(d) {}
};

class MI: public D1, public D2
{
public:
  MI(): Base(), D1(), D2() {}
  MI(int j): Base(j), D1(j), D2(j) {}
  MI(const MI &m): Base(m), D1(m), D2(m) {}
};

class Final: public MI, public Class
{
public:
  Final(): Base(), MI(), Class() {}
  Final(int j): Base(j), MI(j) {}
  Final(const Final &f): Base(f), MI(f) {}
};
