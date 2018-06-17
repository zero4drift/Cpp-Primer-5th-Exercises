// void swap(message &lhs, Message &rhs)
// its implementation really swaps the contents of the two passed in arguments,
// and Message &Message::operator=(const Message &rhs) has a const reference type parameter, if this copy assignment operator calls swap(message &lhs,, Messag &rhs),
// the operations within swap is illegal;

// even though there is a way of copy initializing a non-const temp object from rhs, and pass it to swap as second argument, which would make it reasonable;
// but there is a lot of unnecessary work defined in swap for copy assignment operator; for example, destruction and rebuild of the message-folders relationship of the second parameter is a waste of time and space.
