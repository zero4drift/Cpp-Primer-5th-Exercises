class X;
class Y;

class X
{
  Y *py = nullptr;		// p47
};

class Y
{
  X x;
};
