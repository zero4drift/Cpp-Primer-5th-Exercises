// position 1 replaced by using declarations of all Exercise namespace members;
// would bring name conflict of variable ivar defined in global scope and variable ivar defined in namespace Exercise;
// this bug could be found out at the ivar using declaration;

// position 2
// name conflict of variable dvar defined in local scope and variable dvar defined in namespace Exercise;
// this bug could be found out at the definition of local variable dvar;

// position 1 replaced by using directive of namespace Exercise;
// name conflict same as the first situation;
// while this bug would not be found out until the '++ivar;' expression inside function manip;

// position 2
// same as the above one.
