// iter vector<string>::iterator
// *iter++, legal, increase iterator iter by 1, get the string element which is pointed by the original iter's content.
// (*iter)++, get the string which is pointed by iter, then increase this string by 1, return the original string value; illegal, string object does not support rear ++ operator
// *iter.empty(), illegal, that means *(iter.empty()), for that iterator does not have empty() as a member.
// iter->empty(), legal, that means (*iter).empty()
// ++*iter, illegal, the evaluation order is from right to left, while the string type object does not support pre ++ operator
// iter++->empty() legal, call the original iterator iter's member function empty()
