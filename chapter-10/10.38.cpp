// input iterator
// support operators: ==, !=, ++(prefix and suffix), *(result as the right value of one assignment), ->(same as *iter.member), single pass scan.

// output iterator
// support operators: complement of input iterator's support operators, ++(prefix and suffix), *(result as the left value of one assignment), single pass scan.

// forward iterator
// support operators: all of input and out operator's operators, read & write one element for arbitrary times, multi pass scan.

// bidirectional iterator
// support operator: all of input, out, forward iterator's operators, --(prefix, suffix), read & write  elements in a noraml and reverse order, multi pass scan.

// random-access iterator
// support operators: all of input, out, forward, bidirectional iterator's operators, access of arbitrary element whihin constant time, relationship operators(<, <=, >, >=), calculating with integers(+, +=, -, -=), substraction operator for two iterators(-, get the distance between two iterators), subscript operator(iter[n], same as *(iter[n])), multi pass scan.
