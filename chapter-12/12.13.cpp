// auto sp = make_shared<int>();
// auto p = sp.get();
// delete p;

// sp not becomes a dangling pointer, the memory space which is pointed by sp is now freed by expression 'delete p',
// using sp will cause undefined behaviour.
