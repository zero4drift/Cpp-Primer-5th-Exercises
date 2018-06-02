// iter = vi.insert(iter, *iter++);
// illegal

// for that the evaluation of parameters of a function calling maybe not in order,
// in this case, iter may increase it self at first or later, that calling may have different results per processing, which is not allowed.
