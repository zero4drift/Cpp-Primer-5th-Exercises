// for(int ix = 0; ix != sz; ++ix) { /* ... */ }
// if(ix != sz) // ... variable ix defined in for statement could not be used outside of for statement
// int ix = 0;
// for(: i != sz; ++ix) { /* ... */ }
// if(ix != sz) // ...

// int ix; // variable ix not initialized, should be int ix = 0;
// for(ix != sz; ++ix) { /* ... */ } // missing initializer, which should be an empty statement when the initialize could be ignored.
// for(; ix != sz; ++ix) { /* ... */ }

// for(int ix = 0; ix != sz; ++ix, ++sz) { /* ... */ } // possibely a infinite loop
// for(int ix = 0; ix != sz; ++ix) { /* ... */ }
