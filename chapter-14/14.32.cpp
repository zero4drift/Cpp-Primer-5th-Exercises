#include <iostream>
#include "StrBlob.h"

class StrBlobPtr_Ptr
{
  StrBlobPtr *ptr = nullptr;
public:
  StrBlobPtr_Ptr() = default;
  StrBlobPtr_Ptr(StrBlobPtr *p): ptr(p) {}
  StrBlobPtr operator->();
  // maybe StrBlobPtr *operator->(); ?
};

StrBlobPtr StrBlobPtr_Ptr::operator->()
{
  return *ptr;
}

int main()
{
  StrBlob sb{"hello", "world"};
  StrBlobPtr iter = sb.begin();
  StrBlobPtr_Ptr p(&iter);
  std::cout << p->size() << std::endl; // finally calls size() member function of string class type. 
}
