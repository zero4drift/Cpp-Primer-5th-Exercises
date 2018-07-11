// When a Query class type object is copied:
// would call the synthesized copy constructor of Query class, then the copy constructor of shared_ptr<Query_base> is called to constructor the new Query object's data member q, and the use count of both shared_ptr objects increase by 1;

// move
// since shared_ptr<Query_base> has a move constructor and there is no self-defined copy control members within Query, there is a synthesized move constructor, it is called to move construct the new Query object's data member q, the use-count stay unchanged;

// assignment
// synthesized copy-assignment operator or synthesized move-assignment operator: depenes on whether it is copy assignment or move assignment, this would call copy-assignment operator or move-assignment operator of shared_ptr<Query_base> to assign the left Query object's data member q, and use count increase by 1 or stay unchanged;

// destruction
// synthesized destructor: just call the destructor of shared_ptr<Query_base> member; depends on the use-count of this shared_ptr object, if it comes to 0 the destructor of the pointed object would be called(which destructor relies on its dynamic type).
