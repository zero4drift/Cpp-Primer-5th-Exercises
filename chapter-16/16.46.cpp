////////////////////////////////////////////////////
// for(size_t i = 0; i != size(); ++i)		  //
//   alloc.construct(dest++, std::move(*elem++)); //
////////////////////////////////////////////////////

// new string object constructed in new dynamic memory space takes over the resource owned by the original string which is allocated in another dynamic memory;
// with a for loop, old string objects' resouce is not owned by new constructed string objects, then the old could be safely destructed.
