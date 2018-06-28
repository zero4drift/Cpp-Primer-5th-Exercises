// HasPtr hp = hp2;
// hp2 is lvaule, using copy constructor to initialize hp, hp2 stays unchanged, hp is the copy of hp2;

// HasPtr hp = std::move(hp2);
// std::move(hp2) returns a rvalue reference binded to lvalue hp2;
// so using move constructor to initialize hp, hp gets the control of the resouces owned by hp2;
// while hp2 is valid, in a destruction-safe state, but there is no gurantee of the hp2's contents.

// as illustreted in text, both expressions use constructors, not assignment operators, so parameter rhs is not involved in this context. 
