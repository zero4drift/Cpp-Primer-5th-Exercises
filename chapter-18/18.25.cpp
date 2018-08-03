// class D1: public Base1 { /*...*/ };
// class D2: public Base2 { /*...*/ };
// class MI: public D1, public D2 { /*...*/ };

// Base1 *pb1 = new MI;
// Base2 *pb2 = new MI;
// D1 *pd1 = new MI;
// D2 *pd2 = new MI;

// (a) pb1->print();
// MI::print();

// (b) pd1->print();
// MI::print();

// (c) pd2->print();
// MI::print();

// (d) delete pb2;
// MI::~MI():

// (e) delete pd1;
// MI::~MI():

// (f) delete pd2;
// MI::~MI();
