Sales_data first_item(cin);	// Sales_data(istream &is) {read(is, *this);} data members depend on cin

int main()
{
  Sales_data next;		// Sales_data(string s = ""): bookNo(s) {} bookNo "", units_sold 0, revenue 0.0
  Sales_data last("9-999-99999-9"); // Sales_data(string s = ""): bookNo(s) {} bookNo "9-999-99999-9", units_sold 0, revenue 0.0 
}
