// a, 0-201-99999-9 10 24.95 generates a valid Sales_data object with right data members.
// b, 10 24.95 0-210-9999-9 these inputs would deduce input failure in istream object, due to the last input could not be stored in a double object, finally the object is reset to an emtpy Sales_data object by assign a newly default constructed Sales_data object to it.
