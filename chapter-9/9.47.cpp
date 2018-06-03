#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main()
{
  string s("ab2c3d7R4E6");
  string number("0123456789");
  string albetical("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
  string::size_type index = 0;
  while((index = s.find_first_of(number, index)) != string::npos)
    {
      cout << "found number at index: " << index
	   << " element is: " << s[index] << endl;
      ++index;
    }
  index = 0;
  while((index = s.find_first_of(albetical, index)) != string::npos)
    {
      cout << "found albetical at index: " << index
	   << "element is: " << s[index] << endl;
      ++index;
    }
  index = 0;
  while((index = s.find_first_not_of(albetical, index)) != string::npos)
    {
      cout << "found number at index: " << index
	   << " element is: " << s[index] << endl;
      ++index;
    }
  index = 0;
  while((index = s.find_first_not_of(number, index)) != string::npos)
    {
      cout << "found albetical at index: " << index
	   << "element is: " << s[index] << endl;
      ++index; 
    }
}
