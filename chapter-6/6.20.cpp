// reference type parameter of function should be a reference to constant when there is no need to modify the original passed argument.

// situation that a parameter of function should be a reference to constant, but due to mistakes that it is settled as a reference, that parameter could not accept constant variable, literal type or certain type which needs convertion, what's worse, the function body may modify the original variable which is referenced to and the compiler would allow it.
