// Change the parameter type of 'const Query &' to 'shared_ptr<Query_base>' for NotQuery, BinaryQuery, AndQuery and OrQuery class's constructor, use passed in argument to initialize data member shared_ptr<Query_base>;
// the call of eval and rep inside class type now uses shared_ptr<Query_base> data members and '->' operator.
// three overload operator functions should change its paramter type from 'const Query &' to 'shared_ptr<Query_base>', and its return type from 'Query' to 'shared_ptr<Query_base>' too. 
// in a word, the interface layer of Query class is replaced by direct operation of shared_ptr<Query_base>.
