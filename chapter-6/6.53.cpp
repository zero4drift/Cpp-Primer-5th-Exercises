int calc(int&, int&);
int calc(const int&, const int&); // accepts constant int arguments, while called with non constant int arguments the first one would be choosed.

int calc(char*, char*);
int calc(const char*, const char*); // pattern is same as the previous one, while the type is const char* and char* now.

int calc(char*, char*);
int calc(char* const, char* const); // illegal, would results in ambiguous call, for that both functions would be precisely match when call calc(&s1, &s2) no matter s1 or s2 is const pointer or not.
