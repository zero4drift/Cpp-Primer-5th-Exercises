// specific pointer are 'shared' by shared_type type objects, if new one wants to share, old one does not need to 'release' it, and it is meaningless to provide this member because other shared_ptr that share the same object can still delete it;
// while for unique_ptr, if new one wants to get the control, old one must 'release' the pointed object.
// That is right.
