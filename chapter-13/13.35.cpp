// is using synthesized version of copy control members:

// for copy constructor: no folder contains the pointer which points to this newly constructed Message object;
// for destructor: even destructed, folders still contains the pointer which points to the invalid memory space which once stored this destructed object.
// for copy assignment constructor: this case is a combination of copy constructor and destructor illustrated above, the folders-message relationship stays the same but it should have been updated.
