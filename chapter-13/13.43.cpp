// see StrVec.h.

// the original one is better, use for loop, it could destroy elememts in a reverse order as required, that form is more flexible.
// thr for_each one could not destroy elements in a reverse order, for the string poniter could not behave like a reverse iterator, the form of this for_each syntax has its advantages of simple and easy to use, but has more restrictions than for type syntax.
