// copy: copy TextQuery or QueryResult object would copy every mamber of it, and would increase the reference count of the object which is pointed by the share_ptr member;
// assignment: assign TextQuery or QueryResult object would assign every mamber of it, and would increase the reference count of the object which is pointed by the share_ptr member;
// destruct: destruct TextQuery or QueryResult object would destruct every mamber of it, and would decrease the reference count of the object which is pointed by the share_ptr member;