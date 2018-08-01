// using declaration
// introduces one member of specified namespace at one time;
// could put in global scope, local scope, namespace scope and class scope;
// name conflict bug easy to find and correct;

// usiing directive
// make all names of specified namespace visible and accessible;
// could put in global scope, local scope and namespace scope, but not class scope;
// more complicated mechanism, it lifts namespace members to the most close outer scope which includes namesapce itself and using directive;
// more likely to bring name conflict issue, bug hard to find and correct;
