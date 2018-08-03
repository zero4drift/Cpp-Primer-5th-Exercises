// class Class { ... };
// class Base: public Class { ... };
// class D1: virtual public Base { ... };
// class D2: virtual public Base { ... };
// class MI: public D1, public D2 { ... };
// class Final: public MI, public Class { ... };

// (a)
// Class();
// Base();
// D1();
// D2();
// MI();
// Class();
// Final();

// (b)
// one Base sub object, two Class sub objects;

// (c)
// Base *pb;
// Class *pc;
// Mi *pmi;
// D2 *pd2;
// 1. pb = new Class;
// illegal, Base class pointer could not be converted to its derived class pointer;
// 2. pc = new Final;
// illegal, ambiguous, which Calss sub object?
// 3. pmi = pb;
// illegal, same as 1;
// 4. pd2 = pmil
// legal;
