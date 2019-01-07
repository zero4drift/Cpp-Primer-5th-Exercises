#ifndef SALES_DATA_EXCEPTION
#define SALES_DATA_EXCEPTION


#include <stdexcept>
#include <string>

using std::runtime_error;
using std::logic_error;
using std::string;

class out_of_stock: public runtime_error
{
 public:
  explicit out_of_stock(const string &s): runtime_error(s) {}
};

class isbn_mismatch: public logic_error
{
 public:
  explicit isbn_mismatch(const string &s):
  logic_error(s) {}
 isbn_mismatch(const string &s, const string &lhs, const string &rhs):
  logic_error(s), left(lhs), right(rhs) {}
  string left, right;
};


#endif
