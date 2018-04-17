// string s = "world";
// string p1 = s + s[s.size() - 1] == 's' ? "" : "s";
// equals to (s + s[s.size() - 1]) == 's' ? "" : "s"
// which compares a string object wiht a char object
// which is illegal
// string p1 = s + (s[s.size() - 1] == 's') ? "" : "s";
