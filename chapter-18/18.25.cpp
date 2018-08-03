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
// D2::~D2();
// Base2::~Base2();
// D1::~D1();
// Base1::~Base1();

// (e) delete pd1;
// same as the former one;

// (f) delete pd2;
// same as the former one;
