// 'first_free++' keeps the original value of i as temp, increase first_free itself, and return the temp;
// if use '++first_free', increase first_free, and return it; that is not right, if use that version, it would not construct the specified string object at right place but the place next to it, which means, this operation would skip the right place.
