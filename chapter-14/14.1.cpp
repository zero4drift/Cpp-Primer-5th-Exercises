/* diff */
// 1. an overload operator function could be called directly.
// 2. an overload operator function must either be a member of class of have at least one parameter of class type.
// 3. A few built-in operators guarantee the order in which operands are evaluated. These overload versions of these operators do not preserve order of evaluation and/or shourt-circuit evaluation, it is usually a bad idea to overload them.

/* same */
// The logic pattern are identical, for example, the overload operator should return a reference if the related built-in operator returns a reference.

