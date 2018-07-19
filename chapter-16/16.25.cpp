#include <string>
#include <vector>
#include "Sales_data.h"

extern template class std::vector<std::string>; // instantiation declaration, the definition of it is somewhere else
template class std::vector<Sales_data>;		// instantiation definition, the compiler will generate code fot it. 
