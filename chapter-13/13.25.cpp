// See StrBlob.h
// copy onstructor must allocate a new dynamic memory space for the content copied from the place pointed by original StrBlob object's shared_ptr, use the new shared_ptr object to initialize self's data member.

// copy assignment operator behaves almost like copy constructor, but it does not initialize data member, instead it assigns the new shared_ptr value to it.
// what's more, operator does not need to explicitly free the dynamic memory originally pointed by the old value of data member, for data's type is shared_ptr, the dynamic space arranged by shared_ptr would be automatically released when its reference count decreases to zero.

// StrBlob could rely its own synthesized destructor, for there is only one data member, and class type of member itself owns destrucor.
