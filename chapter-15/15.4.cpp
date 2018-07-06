// class Base { ... };

// a. class Derived : public Derived { ... }
// illegal, one class could not derive from itself.

// b. class Derived : private Base { ... }
// legal.

// c. class Derived : public Base;
// illegal, declaration of a class shoud not include its class derivation list.
