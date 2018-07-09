// Due to the fact that we have defined a constructor with paremeters for Disc_quote class, then there would be no default constructor fot this class;
// but there is a default constructor defined within Bulk_quote class, which is a derived class of Disc_quote; when this constructor is called, it would call the default constructor of Disc_quote class to construct a Disc_quote sub-object;
// so we must define a default constructor for Disc_quote class, or the calling of default constructor of Bulk_quote would fail.
