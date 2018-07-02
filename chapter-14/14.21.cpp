//////////////////////////////////////////////////////////////////////
// Sales_data operator+(const Sales_data &d1, const Sales_data &d2) //
// {								    //
//   Sales_data temp(d1);					    //
//   temp.units_sold += d2.units_sold;				    //
//   temp.revenue += d2.revenue;				    //
//   return temp;						    //
// }								    //
// 								    //
// Sales_data &Sales_data::operator+=(const Sales_data &d)	    //
// {								    //
//   *this = *this + d;						    //
//   return *this;						    //
// }								    //
//////////////////////////////////////////////////////////////////////

// disadvantages:
// redundant work compared to the original version defined in section 14.3 and 14.4, for example, the unnecessary copy-assignment operation within overload operator +=.
