// Change the parameter type of 'const Query &' to 'const Query_base *' NotQuery, BinaryQuery, AndQuery and OrQuery class's constructor, use passed in argument to initialize data member shared_ptr<Query_base>;
// the call of eval and rep inside class type now uses shared_ptr<Query_base> data members and '->' operator.
// in a word, the interface layer of Query class is replaced by direct operation of shared_ptr<Query_base>.
