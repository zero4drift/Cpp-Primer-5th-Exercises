// For self assignment of Token type object, since the data member tok is exactly the same;

// for copy assignment, follow the way which is illustrated in text book;
// there is no call of constructor or destructor of string class type and Sales_data class type, for any member of union the correspond assignment operation would do the job;

// for mvoe assignment, as in my implementation;
// check if it is a self-assignment, if so, do nothing 'return *this'.
