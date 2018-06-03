#include <string>
#include <stdexcept>
#include <iostream>

using std::string;
using std::stoi;
using std::runtime_error;
using std::cout;
using std::endl;

unsigned month_transform(const string&);

struct date
{
  date(const string &s);
  void print() {cout << year << " " << month << " " << day << endl;}
private:
  unsigned year;
  unsigned month;
  unsigned day;
};

date::date(const string &s)
{
  // type1: January 1, 1900
  string type1_symbol = ",";
  // type2: 1/1/1990
  string type2_symbol = "/";
  // type3: Jan 1 1900
  string type3_symbol = " ";
  string::size_type index;
  if((index = s.find(type1_symbol)) != string::npos)
    {
      auto index_of_first_number = s.find_first_of("0123456789");
      day = stoi(s.substr(index_of_first_number, index - index_of_first_number));
      string m = s.substr(0, index_of_first_number - 1);
      month = month_transform(m);
      auto index_of_next_number = s.find_first_of("0123456789", index_of_first_number + 1);
      year = stoi(s.substr(index_of_next_number));
    }
  else if((index = s.find(type2_symbol)) != string::npos)
    {
      auto index_of_first_number = s.find_first_of("0123456789");
      day = stoi(s.substr(index_of_first_number, index - index_of_first_number));
      index = s.find(type2_symbol, index_of_first_number + 1);
      auto index_of_second_number = s.find_first_of("0123456789", index_of_first_number + 1);
      month = stoi(s.substr(index_of_second_number, index - index_of_second_number));
      auto index_of_third_number = s.find_first_of("0123456789", index_of_second_number + 1);
      year = stoi(s.substr(index_of_third_number));
    }
  else if((index = s.find(type3_symbol)) != string::npos)
    {
      string m = s.substr(0, index);
      month = month_transform(m);
      auto index_of_first_number = s.find_first_of("0123456789");
      index = s.find(type3_symbol, index_of_first_number);
      day = stoi(s.substr(index_of_first_number, index - index_of_first_number));
      auto index_of_second_number = s.find_first_of("0123456789", index);
      year = stoi(s.substr(index_of_second_number));
    }
  else
    throw runtime_error("Invalid argument " + s);
}

unsigned month_transform(const string &s)
{
  if(s == "January" || s == "Jan") return 1;
  else if(s == "February" || s == "Feb") return 2;
  else if(s == "March" || s == "Mar") return 3;
  else if(s == "April" || s == "Apr") return 4;
  else if(s == "May" || s == "May") return 5;
  else if(s == "June" || s == "Jun") return 6;
  else if(s == "July" || s == "Jul") return 7;
  else if(s == "August" || s == "Aug") return 8;
  else if(s == "September" || s == "Sep") return 9;
  else if(s == "October" || s == "Oct") return 10;
  else if(s == "November" || s == "Nov") return 11;
  else if(s == "December" || s == "Dec") return 12;
  else throw runtime_error("Invaild argument " + s);
}

int main()
{
  string s1 = "January 1, 1990";
  string s2 = "1/1/1990";
  string s3 = "Jan 1 1990";
  date date1(s1);
  date1.print();
  date date2(s2);
  date2.print();
  date date3(s3);
  date3.print();
}
