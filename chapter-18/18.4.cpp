// This catch expressions alignment illustrated in section 18.1.2 should be reversed, for that the certain exception object would always match the first catch expression if object's type is derived from exception class.

// try { // C++ stand library }
// catch (overflow_error eobj) { //... }
// catch(const runtime_error &re) { //... }
// catch(exception) { //... }
