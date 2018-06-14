// auto p = new int();
// auto sp = make_shared<int>();

// a: process(sp), legal, pass an shared_ptr<int> object to process
// b: process(new int()), illegal, pass an built-int pointer type object to process, shared_ptr does not support implicit tramsform from built-int pointer to shared_ptr type
// c: process(p), illegal, same as b
// d: process(shared_ptr<int>(p)), legal, but not a good practice, directly initializes a shared_ptr object from built-in pointer type, same as a
