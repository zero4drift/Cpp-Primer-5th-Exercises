// Because overload '!=' operator is more widely implemented in C++ standard library class types than overload '<' operator;
// then when define a template which would compare two objects, code assumes that passed in arguments'type supports specified relationship operator, use '!=' operator is safer than '<'.
