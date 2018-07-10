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
using std::vector;
using std::string;
using std::set;
using std::shared_ptr;
using std::make_shared;
using std::getline;

class QueryResult;

class TextQuery
{
 public:
  using line_no = vector<string>::size_type;
  TextQuery(ifstream &infile);
  TextQuery(const TextQuery &);
  TextQuery &operator=(const TextQuery &);
  QueryResult query(const string &s) const;
 private:
  friend QueryResult;
  shared_ptr<vector<string>> sp1;
  shared_ptr<map<string, set<line_no>>> sp2;
};

TextQuery::TextQuery(ifstream &infile):
sp1(new vector<string>), sp2(new map<string, set<line_no>>)
{  
  line_no line_number = 0;
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

TextQuery::TextQuery(const TextQuery &t): sp1(make_shared<vector<string>>(*t.sp1)), sp2(make_shared<map<string, set<line_no>>>(*t.sp2)) {}

TextQuery &TextQuery::operator=(const TextQuery &t)
{
  sp1 = make_shared<vector<string>>(*t.sp1);
  sp2 = make_shared<map<string, set<line_no>>>(*t.sp2);
  return *this;
}

class QueryResult
{
  friend ostream &print(ostream &, const QueryResult &);
  string search_word;
  set<TextQuery::line_no> nodata;
  set<TextQuery::line_no> *result = &nodata;
  shared_ptr<vector<string>> sp1;
  shared_ptr<map<string, set<TextQuery::line_no>>> sp2;
  public:
  QueryResult(const string &s, const TextQuery &t);
  QueryResult(const QueryResult &);
  QueryResult &operator=(const QueryResult &);
};

QueryResult::QueryResult(const string &s, const TextQuery &t):
sp1(t.sp1), sp2(t.sp2), search_word(s)
{
  auto iter = (*sp2).find(search_word);
  auto last = (*sp2).end();
  if(iter != last)
    result = &(iter->second);
}

QueryResult::QueryResult(const QueryResult &q): sp1(make_shared<vector<string>>(*q.sp1)), sp2(make_shared<map<string, set<TextQuery::line_no>>>(*q.sp2)) {}

QueryResult &QueryResult::operator=(const QueryResult &q)
{
  sp1 = make_shared<vector<string>>(*q.sp1);
  sp2 = make_shared<map<string, set<TextQuery::line_no>>>(*q.sp2);
  return *this;
}

ostream &print(ostream &o, const QueryResult &q)
{
  auto n = (*q.result).size();
  o << "element occurs " << n << " times" << endl;
  auto result = q.result;
  for(const auto &l : *result)
    cout << "\t(line " << l + 1 << ") "
	 << (*q.sp1)[l] << endl;
  return o;
}

QueryResult TextQuery::query(const string &s) const
{
  return QueryResult(s, *this);
}
