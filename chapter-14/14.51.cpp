// void calc(int);
// void calc(LongDouble);		// class LongDouble defined in 14.50
// double dval;
// calc(dval);			// finally call 'void calc(int)'

// double object dval converted to int type: built-in type conversion;
// double object dval converted to LongDouble class type: class type conversion
// for built-in arithmetical type conversion has higher priority than class type conversion;
// then the first calc one would be called.
