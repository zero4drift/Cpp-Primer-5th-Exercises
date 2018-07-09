// Base *p = &dl;
// d1: Pub_Derv
// legal

// p = &d2;
// d2: Priv_Derv
// illegal, for the derivation access specifier of Priv_Derv is private, conversion from Priv_Derv to its base class Base is forbidden;

// p = &d3;
// d3: Prot_Derv
// illegal, for the derivation access spedifier of Prot_Derv is protected, conversion from Priv_Derv to its base class Base is forbidden;

// p = &dd1;
// dd1: Derived_from_Public
// legal

// p = &dd2;
// dd2: Derived_from_Private
// illegal, same reason as the second one;

// p = &dd3;
// dd3: Derived_from_Protected
// illegal, same reason as the third one.
