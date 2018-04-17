// if(p = getPtr() != 0) the expression inside could be read as p = (getPtr() ! = 0); p's value is the value converted from a bool value computed from the right expression, which is unexpected. if((p = getPtr()) != 0) would be ok.

// if(i = 1024) the expression inside is an assignment, the return result of which is the left operand i, that is not illegal, but the initial purpose is to check if i equals to 1024 and make variable i unchanged, so if(i == 1024) is the right solution.
