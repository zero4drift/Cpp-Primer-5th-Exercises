// replace(beg, end, old_val, new_val)
// replaces old_val among elements spedified by [beg, end) with new_val

// replace_if(beg, end, pred. new_val)
// replaces element which makes pred return non-zero result with new_val, element belongs to the range spedified by [beg, end).

// replace_copy(beg, end, dest, old_val, new_val)
// mostly same as replace(beg, end, old_val, new_val), but would not modify the container spedified by the first two arguments, just copies the result to the container spedified by dest.

// replace_copy_if(beg, end, dest, pred, new_val)
// mostly same as replace_copy(beg, end, dest, old_val, new_val), but only replaces the element which makes pred return non-zero result, that element is spedified by rang[beg, end). 
