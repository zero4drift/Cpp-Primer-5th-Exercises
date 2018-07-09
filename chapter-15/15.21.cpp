#include <string>

using std::string;

class Employee
{
private:
  string name;
  string department;
  string address;
  string contact;
protected:
  int salary;
public:
  Employee() = default;
  Employee(string n, string d, string a, string c, int s):
    name(n), department(d), address(a), contact(c), salary(s) {}
  string get_name() {return name;}
  string get_department() {return department;}
  string get_address() {return address;}
  string get_contact() {return contact;}
  virtual int get_payment() {return salary;}
};

class Manager: public Employee
{
protected:
  int bonus;
public:
  Manager() = default;
  Manager(string n, string d, string a, string c, int s, int b):
    Employee(n, d, a, c, s), bonus(b) {}
  int get_payment() override {return salary + bonus;}
};

class CEO: public Manager
{
protected:
  int share;
public:
  CEO() = default;
  CEO(string n, string d, string a, string c, int s, int b, int sh):
    Manager(n, d, a, c, s, b), share(sh) {}
  int get_payment() override {return salary + bonus + share;}
};
