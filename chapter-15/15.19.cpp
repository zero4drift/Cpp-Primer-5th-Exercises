// void memfcn(Base &b) { b = &this; }
// as member function

// for Base:
// legal;

// for Pub_Derv:
// legal;

// for Pro_Derv;
// legal;

// for Priv_Derv:
// legal;

// for Derived_from_Public:
// legal;

// for Derived_from_Private:
// illegal;
// for the derivation access specifier of Priv_Derv is private, member or friend of derivaed class of Priv_Derv would nerver call the conversion from Derived_from_private to Base class.

// for Derived_from_Protected:
// legal;
