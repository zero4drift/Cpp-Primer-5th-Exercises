// int ix = 1024, *pi = &ix. *pi2 = new int(2048);
// typedef unique_ptr<int> IntP;

// a: IntP p0(ix); illegal, unique_ptr must be binded to a ptr which is the return value of operator 'new'.
// b: IntP p1(pi); illegal, same reason as a.
// c: IntP p2(pi2); legal.
// d: IntP p3(&ix); illegal, same reason as a.
// e: IntP p4(new int(2048)); legal;
// f: IntP p5(p2.get()); illegal, p2 has not yet release its pointer, poniter is still 'owned' by p2.
