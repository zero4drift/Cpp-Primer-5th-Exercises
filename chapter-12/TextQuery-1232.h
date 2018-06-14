#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <memory>
#include <initializer_list>
#include "StrBlob.h"

using std::ifstream;
using std::istringstream;
using std::ostream;
using std::cout;
using std::endl;
using std::map;
using std::vector;
using std::string;
using std::set;
using std::shared_ptr;
using std::getline;
using std::initializer_list;

class QueryResult;

class TextQuery
{
 public:
  using line_no = vector<string>::size_type;
  TextQuery(ifstream &infile);
  QueryResult query(const string &s);
 private:
  friend QueryResult;
  StrBlob sb;
  shared_ptr<map<string, set<line_no>>> sp2;
};

TextQuery::TextQuery(ifstream &infile):
sp2(new map<string, set<line_no>>)
{  
  line_no line_number = 0;
  string line;
  while(getline(infile, line))
    {
      // store line in vector<string>
      sb.push_back(line);
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
  friend ostream &print(ostream &, const QueryResult &);
  string search_word;
  StrBlob qsb;
  set<TextQuery::line_no> nodata;
  set<TextQuery::line_no> *result = &nodata;
  shared_ptr<map<string, set<TextQuery::line_no>>> sp2;
 public:
  QueryResult(const string &s, TextQuery &t);
};

QueryResult::QueryResult(const string &s, TextQuery &t):
qsb(t.sb), sp2(t.sp2), search_word(s)
{
  auto iter = (*sp2).find(search_word);
  auto last = (*sp2).end();
  if(iter != last)
    result = &(iter->second);
}

ostream &print(ostream &o, const QueryResult &q)
{
  auto n = (*q.result).size();
  o << "element occurs " << n << " times" << endl;
  auto result = q.result;
  for(const auto &l : *result)
    {
      ConstStrBlobPtr csbp(q.qsb, l);
      cout << "\t(line " << l + 1 << ") "
	   << csbp.deref() << endl;
    }
  return o;
}

QueryResult TextQuery::query(const string &s)
{
  return QueryResult(s, *this);
}
