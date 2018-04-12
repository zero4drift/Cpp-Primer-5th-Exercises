#include <vector>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::string;

vector<int> v1;		        // empty
vector<int> v2(10);		// 10 elements are all 0
vector<int> v3(10, 42);	        // 10 elements are all 42
vector<int> v4{10};		// 1 elements with value 10
vector<int> v5{10, 42};	        // 2 elements, first 10, second 42
vector<string> v6{10};          // 10 elements, all empty strings
vector<string> v7{10, "hi"};	// 10 elements, every one is "hi"

int main()
{
  for(auto it = v2.begin(); it != v2.end(); ++it) cout << *it << endl;
  for(auto it = v3.begin(); it != v3.end(); ++it) cout << *it << endl;
  for(auto it = v4.begin(); it != v4.end(); ++it) cout << *it << endl;
  for(auto it = v5.begin(); it != v5.end(); ++it) cout << *it << endl;
  for(auto it = v6.begin(); it != v6.end(); ++it) cout << *it << endl;
  for(auto it = v7.begin(); it != v7.end(); ++it) cout << *it << endl;
}
