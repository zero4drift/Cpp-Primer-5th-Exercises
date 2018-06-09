// pos.first->second
// equals to:
// (pos.first)->second
// and also:
// (*(pos.first)).second
// pos: pair<map<string, string>::iterator, map<string, string>::iterator>
// pos.first: map<string, string>::iterator
// *(pos.first): map<string, string>::value_type
// (*(pos.first)).second: map<string, string>::mapped_type
