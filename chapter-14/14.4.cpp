// a %; not a member of class type, 1st: does not modify the operands, 2nd: operands may need convertion;
// b %=; should ba a member of class type, 1st: would modiry the left operand;
// c ++; member, same reason as b;
// d ->; member, -> operator must be a member of class type.
// e <<: shoud not be member, because left operand is ostream object, even though there is a overload << operator defined within class type as member, the expression would not call it.
// f &&: not a member, same reason as a;
// g ==: not a member, same reason as a;
// f (): member, () operator must be a member of class type.

