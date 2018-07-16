// function make_shared<T> accepts function arguments which could be passed in to type T's corresponding constructor to initialize a T type object allocated in dynamic memory;
// and compiler could not deduce T from arguments of call of make_shared without specifie any template type argument;
// then a call like make_shared(args) is illegal.
