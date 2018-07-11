// See 15.28.cpp.
// The output is different from the previous one;
// for the first version of basket's element type is Quote, when pushed a Bulk_quote object into this vector, a Quote object as a copy of the Qutoe part of Bulk_quote object is pushed in, at last we call the Quote's net_price version;
// for the next version of basket's element type is shared_ptr<quote>, a shared_ptr<quote> could be binded to a Bulk_quote object because Bulk_quote public derived from Quote class, then the version of net_price is determined by object's dynamic type.
