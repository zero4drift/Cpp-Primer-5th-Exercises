// If resp is defined within loop body, there would be a compile error;
// when the loop body ends, the variables defined within it would be destructed, after that, it's illegal to get access to such variables in outer scope.
