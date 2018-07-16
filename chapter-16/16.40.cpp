template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
  return *beg;
}

// legal;
// the type of passed in arguments of fcn3 must support '*' operator;
// return type is the type of element which is pointed by beg.
