// copy-assignment operator defines what happened when assign an object to another object with same type.
// when assign an object to another object with same type, copy-assignment operator would be called.
// for sone class type, copy-assignment operator prevents the assignment of objects of this calss type, but mainly copy-assignment operator would assign every non-static member of right operand to the corresponding member of left operand using the copy-assignment operator for the type of the member.
// if there is no copy-assignment operator defined within a class type, compiler would generate a synthesized copy-assignment oeperator for it.
