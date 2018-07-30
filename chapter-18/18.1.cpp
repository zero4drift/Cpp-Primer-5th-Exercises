// range_error r("error");
// throw r;
// type of exception object: range_error

// exception *p = &r;
// throw *p;
// type of exception object: range_error

// 'throw *p' replaced by throw p;
// pointer points to a local object;
// the matched catch expression may use this pointer to access a destructed object, which would casue an error.
