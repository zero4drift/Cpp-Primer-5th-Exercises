// specific pointer are 'shared' by shared_type type objects, if new one wants to share, old one does not need to 'release' it;
// while for unique_ptr, if new one wants to get the control, old one must 'release' the pointed object.
