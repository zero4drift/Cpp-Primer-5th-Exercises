#include <string>

using std::string;

struct Sales_data		// using aggregate class 
{
  string bookNo;
  unsigned units_sold;
  double revenue;
};

int main()
{
  Sales_data item = {"978-0590353403", 25, 15.99};
  // legal
  // item.bookNo = "978-0590353403"
  // item.units_sold = 25
  // item.revenue = 15.99
}
