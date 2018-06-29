// Within a class type, if the first parameter of one constructor is the reference of the class type itself, and left parameters all have default values, then this constrcutor is copy constructor.

// copy constructor is utilized in copy initialization:
// 1. Define variable using an =;
// 2. Pass an object as an argument to a parameter of noreference type;
// 3. Return an object from a function that has a nonreference return type;
// 4. Brace initialize the elements in an array or the members of an aggregate class;
// 5. Some class types also use copy initializetion for the objects they allocate.
