// Only when 1.5*svec.size() > svec.capacity() (1024) there is a memory re-allocation for svec, and the new elements are value initialized;
// else just put new elements in the back of svec, all value initialized.
