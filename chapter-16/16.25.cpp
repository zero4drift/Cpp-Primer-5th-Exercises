#include <string>
#include <vector>
#include "Sales_data.h"

extern template class std::vector<std::string>; // instantiation declaration
template class std::vector<Sales_data>;		// instantiation definition 
