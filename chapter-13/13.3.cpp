// copy a StrBlob object would copy every non-static member of it, and StrBlob class type has a shared_ptr member, copy it will increase the reference count of the object which is pointed by shared_ptr.

// copy a StrBlob object would copy every non-static member of it, StrBlobPtr class type has a weak_ptr member, copy it will not influence the reference count of the object which is pointed by weak_ptr.
