// shared_ptr<int> p(new int(42));
// process(shared_ptr<int>(p.get));

// when the call of precess ends, the variable ptr defined inside function body is deleted, and the memory space which is pointed by ptr is freed, too.
// though pointed to same memory space, the two shared_ptr objects are created individually, their reference count are both 1.
// after this, using shared_ptr p will cause undefined behaviour. 
