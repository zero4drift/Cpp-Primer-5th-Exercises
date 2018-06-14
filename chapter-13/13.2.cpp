// Sales_data::Sales_data(Sales_data rhs)

// try to define a copy constructor of class type Sales_data;
// and the first parameter's type is Sales_data, it is illegal;
// when copy constructor is used in copy initialization, Sales_data object as argument is pass in to copy initialize the paramenter rhs;
// while this copy initialize will call the copy constructor itself;
// a infinite loop in the end;

// so the type of first parameter should be Sales_data&.
