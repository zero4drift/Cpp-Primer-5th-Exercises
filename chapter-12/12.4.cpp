// Because the parameter i is of size_type type, which is vector::size_type, it is unsigned.
// When passed i is a negative number, it would be transformmed to a really large unsigned integer, the comparison between it and data->size() would always turns true if the size is not so large. 
