// When bind a pointer of a reference of base class type to a object of derived class type, the static type is different from the dynamic type.

// class Base { ... };
// class Derived: public Base { ... };
// int f(const Base &b) { ... }

// Derived d;
// Base &b = d;
// Base *p = &d;
// f(d);
