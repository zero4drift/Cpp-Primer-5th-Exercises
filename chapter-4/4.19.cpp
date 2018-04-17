// ptr int*, vec vector<int>, ival int
// ptr != 0 && *ptr++ ptr is not a nullptr and the int value pointed by ptr is not zero
// ival++ && ival if ival's original value is not zero and ival's new value is not zero after increased it by 1
// vec[ival++] <= vec[ival] illegal due to the <= operator not implemented the order of operands evaluation, and the operand modify the value of variable ival, this behavior is undefined; could be changed like this:

// int i = vec[ival];
// int j = vec[++ival];
// vec[j] <= vec[i];
