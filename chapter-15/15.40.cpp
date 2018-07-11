// Within OrQuery, if rhs.eval(text) returns a QueryResult object which points to an empty set, the return value of OrQuery::eval would be same as the result of lhs.eval(text);
// vise versa;
// if both results of rhs.eval and lhs.eval point to an empty set, the return QueryResult of OrQuery::eval points to an empty set, too.
