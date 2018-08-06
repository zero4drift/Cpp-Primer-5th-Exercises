// class A { /* ... */ }
// class B: public A { /* ... */ }
// class C: public B { /* ... */ }
// class D: public B, public A { /* ... */ }

// a
// A *pa = new C;
// B *pb = dynamic_cast<B*>(pa);
// legal;

// b
// B *pb = new B;
// C *pc = dynamic_cast<C*>(pb);
// illegal;

// c
// A *pa = new D;
// this would cause ambiguous error, for D class type object contains two A class type sub-objects, but it seems like this exercise does not foucs on it...
// B *pb = dynamic_cast<B*>(pa);
// legal;
