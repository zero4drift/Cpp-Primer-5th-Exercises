// a: Sales_data &combine(Sales_data);
// b: Sales_data &combine(Sales_data &);
// c: Sales_data &combine(const Sales_data &) const;

// i: Sales_data, s: string

// i.combine(s)
// a: explicitly using s to construct a Sales_data temp object, which is passed as the argument of combine, then it is used to initialize the parameter(copy)
// b: illegal, the parameter is a reference which could not be binded to a temp object
// c: illegal, const member function called by const object should not modify the calling object.
