bool fcn(const Sales_data *trans, Sales_data accum) // accum is copy initialized within this function body, it would be destructed when this function call ends.
{
  Sales_data item1(*trans), item2(accum); // both would be destructed when this function body ends
  return item1.isbn() != item2.isbn(); // the two string temp object would be destructed when the expression ends 
  // and the temp bool object as result of this expression would be destructed after copy initialization of the return value.
}

// since destruction of Sales_data object would lead to the destruction of the string type member, and destruct string object would call its destructor.
// so there would be 2 + 2 + 2 + 1 + 1 = 8 times of calling of destructor.
