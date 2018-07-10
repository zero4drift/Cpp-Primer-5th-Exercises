// Query q = Query("fiery") & Query("bird") | Query("wind")

// a
// constructor:
// Query(const string &);
// WordQuery(const string &);
// AndQuery(const Query &, cosnt Query &);
// OrQuery(const Query &, const Query &);
// BinaryQuery(const Query &, const Query &, string);
// Query_base();
// Query(shared_ptr<Query_base>)

// b
// Query::rep() // missed in first attempt
// BinaryQuery::rep()
// WordQuery::rep()

// c
// OrQuery::eval
// AndQuery::eval
// WordQuery::eval
