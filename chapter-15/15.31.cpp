// Query(s1) | Query(s2) & ~Query(s3);
// returns a Query object binded to a AndQuery object;
// Query(s1) | Query(s2) returns a Query object binded to a OrQuery object;
// ~Query(s3) returns a Query object binded to a NotQuery object;
// the base level are all WordQuery objects.

// Query(s1) | (Query(s2) & ~Query(s3));
// returns a Query object binded to a OrQuery object
// Query(s1) returns a Query object binded to WordQuery object;
// (Query(s2) & ~Query(s3)) returns a Query object binded to a AndQuery object;
// ~Query(s3) returns a Query object binded to a NotQuery object;
// the base level are all WordQuery objects.

// (Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)))
// returns a Query object binded to OrQuery object
// (Query(s1) & (Query(s2))) returns a Query object binded to a AndQuery object;
// (Query(s3) & Query(s4)) returns a Query object binded to a AndQuery object;
// the base level are all WordQuery objects.
