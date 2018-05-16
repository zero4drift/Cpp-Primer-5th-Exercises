// friend is helpful in such a situation: functions as part of interfaces of class but are not member functions, for that data members of class are not accessibile to them, while whith friend declearations inside class, these functions are able to get data members directly.

// The disadvantage is the possibile abusing of this syntax, then functions which are not part of interfaces could also touch data members of class.
