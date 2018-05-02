#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>

using std::istream;
using std::ostream;

struct Sales_data;

istream &read(istream &is, Sales_data &item);

ostream &print(ostream &os, const Sales_data &item);

Sales_data add(const Sales_data &item1, const Sales_data &item2);

#endif
