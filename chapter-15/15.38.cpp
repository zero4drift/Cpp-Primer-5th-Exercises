// BinaryQuery a = Query("fiery") & Query("bird")
// false;
// BinaryQuery is a abstract class, construct of this class type is illegal.

// AndQuery b = Query("fiery") & Query("bird")
// false
// operator&(const Query &, const Query &) returns a object of Query class type, not AndQuery, and there is no available way of conversion from Query to AndQuery.

// OrQuery b = Query("fiery") & Query("bird")
// false
// operator&(const Query &, const Query &) returns a object of Query class type, not OrQuery, and there is no available way of conversion from Query to OrQuery.
