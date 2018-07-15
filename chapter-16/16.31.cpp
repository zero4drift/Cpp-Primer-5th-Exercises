// As described in My_unique_ptr.h;
// if given a statement like this: My_unique_ptr<int, DebugDelete>
// code of destructor: ~My_unique_ptr() {del(p);}
// the destructor of this instantiated class would be expanded like:

// ~My_unique_ptr()
// {
//   cerr << "deleting unique_ptr" << endl;
//   delete p;
// }
