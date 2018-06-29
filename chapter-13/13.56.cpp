///////////////////////////////
// Foo Foo::Sorted() const & //
// {			     //
//   Foo ret(*this);	     //
//   return ret.sorted();    //
// }			     //
///////////////////////////////

// The return statement causes infinite recursively calling, exceeds the max stack depth.
