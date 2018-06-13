#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <memory>

using std::ifstream;
using std::istringstream;
using std::ostream;
using std::cout;
using std::endl;
using std::map;
using std::set;
using std::vector;
using std::string;
using std::set;
using std::size_t;
using std::shared_ptr;
using std::make_shared;
using std::getline;

class QueryResult;

class TextQuery
{
  friend QueryResult;
  shared_ptr<vector<string>> sp1;
  shared_ptr<map<string, set<size_t>>> sp2; 
 public:
  TextQuery(ifstream &infile);
  QueryResult query(const string &s);
};

TextQuery::TextQuery(ifstream &infile):
sp1(make_shared<vector<string>>()), sp2(make_shared<map<string, set<size_t>>>())
{  
  size_t line_number = 0;
  string line;
  while(getline(infile, line))
    {
      // store line in vector<string>
      sp1->push_back(line);
      // scan through the line      
      istringstream ist(line);
      string word;
      while(ist >> word)
	(*sp2)[word].insert(line_number);
      // increase the line_number
      ++line_number;
    }
}

class QueryResult
{
  size_t times = 0;
  string search_word;
  map<size_t, string> result;
  shared_ptr<vector<string>> sp1;
  shared_ptr<map<string, set<size_t>>> sp2;
 public:
  QueryResult(const string &s, TextQuery &t);
  size_t get_times() {return times;}
  map<size_t, string> &get_result() {return result;}
};

QueryResult::QueryResult(const string &s, TextQuery &t):
sp1(t.sp1), sp2(t.sp2), search_word(s)
{
  set<size_t> line_numbers;
  auto iter = (*sp2).find(search_word);
  auto last = (*sp2).end();
  if(iter != last)
    {
      line_numbers = iter->second;
      for(const auto &n : line_numbers)
	{
	  result[n] = (*sp1)[n];
	  ++times;
	}
    }
}

void print(ostream &o, QueryResult &q)
{
  o << "elements occurs " << q.get_times() << " times" << endl;
  if(q.get_times())
    {
      auto result = q.get_result();
      for(const auto &p : result)
	cout << "(line " << p.first << ") "
	     << p.second << endl;
    }
  
}

QueryResult TextQuery::query(const string &s)
{
  return QueryResult(s, *this);
}
