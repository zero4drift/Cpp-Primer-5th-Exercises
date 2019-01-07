#ifndef TEXTQUERY_H
#define TEXTQUERY_H


#include <tuple>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <memory>

using std::tuple;
using std::get;
using std::ifstream;
using std::istringstream;
using std::ostream;
using std::cout;
using std::endl;
using std::map;
using std::vector;
using std::string;
using std::ispunct;
using std::set;
using std::shared_ptr;
using std::make_shared;
using std::getline;


class TextQuery
{
 public:
  using line_no = vector<string>::size_type;
  using QueryResult = tuple
    <
    shared_ptr<vector<string>>,
    shared_ptr<set<line_no>>,
    string
    >;
  TextQuery(ifstream &infile);
  TextQuery(const TextQuery &);
  TextQuery &operator=(const TextQuery &);
  QueryResult query(const string &s) const;
 private:
  shared_ptr<vector<string>> sp1;
  map<string, shared_ptr<set<line_no>>> mp;
};

TextQuery::TextQuery(ifstream &infile):
sp1(new vector<string>)
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
	{
	  if(ispunct(word[word.size() - 1]))
	    word.erase(word.size() - 1);
	  auto &lines = mp[word];
	  if(!lines) lines.reset(new set<line_no>);
	  lines->insert(line_number);
	}
      // increase the line_number
      ++line_number;
    }
}

TextQuery::TextQuery(const TextQuery &t): sp1(make_shared<vector<string>>(*t.sp1)), mp(t.mp) {}

TextQuery &TextQuery::operator=(const TextQuery &t)
{
  sp1 = make_shared<vector<string>>(*t.sp1);
  mp = t.mp;
  return *this;
}

  ostream &print(ostream &o, const TextQuery::QueryResult &q)
  {
    auto n = get<1>(q)->size();
    o << "element occurs " << n << " times" << endl;
    auto result = *get<1>(q);
    for(const auto &l : result)
      cout << "\t(line " << l + 1 << ") "
	   << (*get<0>(q))[l] << endl;
    return o;
  }

auto TextQuery::query(const string &s) const -> QueryResult
{
  static shared_ptr<set<line_no>> nodata(new set<line_no>);
  auto iter = mp.find(s);
  auto last = mp.end();
  if(iter != last)
    return QueryResult(sp1, iter->second, s);
  else
    return QueryResult(sp1, nodata, s);
}


#endif
