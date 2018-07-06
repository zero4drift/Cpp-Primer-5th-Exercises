// See Employee.h.
// class type Employee should define its bool conversion operator, for one Employee object may has no content if it is default constructed(or its data member 'name' is an empty string), and such object used as condition should be converted to bool;
// the bool conversion operator should be explicit, for it is only used in condition case(compiler would implicitly call this explicit conversion operator when encountered in condition expression), and it should not be implicitly called in other cases.
