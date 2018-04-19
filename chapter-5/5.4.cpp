#include <string>

using std::string;

int main()
{
  string s;
  // while(string::iterator iter != s.end()) {/* ... */}, iter is uninitialized
  string::iterator iter = s.begin();
  while(iter != s.end()) ;

  // while (bool status = find(word) {/* ... */}
  // if(!status) {/* ... */}
  // status defined in while loop could only be used inside its scope

  bool status;
  while (status = find(word)) ;
  if(!status) ;
}
