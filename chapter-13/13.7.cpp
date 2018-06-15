// assign a StrBlob object to another StrBlob object would assign every non-static member of it, and StrBlob class type has a shared_ptr member, assign it will increase the reference count of the object which is pointed by right operand's shared_ptr, and decrease the reference count of the object which is pointed by the left operand's shared_ptr .

// assign a StrBlobPtr object to another StrBlobPtr object would assign every non-static member of it, StrBlobPtr class type has a weak_ptr member, assignment of it will not influence the reference count of the object which is pointed by weak_ptr.
