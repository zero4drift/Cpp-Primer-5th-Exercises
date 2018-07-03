#include "StrBlob.h"

class StrBlobPtr_Ptr
{
  StrBlobPtr *ptr = nullptr;
public:
  StrBlobPtr operator->();
  // maybe StrBlobPtr *operator->(); ?
};

StrBlobPtr StrBlobPtr_Ptr::operator->()
{
  return *ptr;
}
