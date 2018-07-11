#ifndef TEXTQUERY1542_H
#define TEXTQUERY1542_H


#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <memory>

using std::ifstream;
using std::istringstream;
using std::ostream;
using std::istream;
using std::cout;
using std::endl;
using std::map;
using std::vector;
using std::string;
using std::ispunct;
using std::set;
using std::shared_ptr;
using std::make_shared;

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
  map<string, shared_ptr<set<line_no>>> mp;
};

istream &get_sentence(istream &is, string &s)
{
  s = "";
  string word;
  while(is >> word)
    {
      char symbol = word[word.size() - 1];
      if(ispunct(symbol))
	{
	  s = s + word;
	  break;
	}
      else
	s = s + word + " "; 
    }
  return is;
}

TextQuery::TextQuery(ifstream &infile):
sp1(new vector<string>)
{  
  line_no line_number = 0;
  string sentence;
  while(get_sentence(infile, sentence))
    {
      // store sentence in vector<string>
      sp1->push_back(sentence);
      // scan through the sentence      
      istringstream ist(sentence);
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

  class QueryResult
  {
    friend ostream &print(ostream &, const QueryResult &);
    string search_word;
    shared_ptr<vector<string>> sp1;
    shared_ptr<set<TextQuery::line_no>> sp2;
  public:
  QueryResult(const string &s,
	      shared_ptr<set<TextQuery::line_no>> p,
	      shared_ptr<vector<string>> file): search_word(s), sp1(file), sp2(p) {}
    QueryResult(const QueryResult &);
    QueryResult &operator=(const QueryResult &);
    set<TextQuery::line_no>::iterator begin() {return sp2->begin();}
    set<TextQuery::line_no>::iterator end() {return sp2->end();} 
    shared_ptr<vector<string>> get_file() {return sp1;}
  };

QueryResult::QueryResult(const QueryResult &q): sp1(make_shared<vector<string>>(*q.sp1)), sp2(make_shared<set<TextQuery::line_no>>(*q.sp2)), search_word(q.search_word) {}

QueryResult &QueryResult::operator=(const QueryResult &q)
{
  sp1 = make_shared<vector<string>>(*q.sp1);
  sp2 = make_shared<set<TextQuery::line_no>>(*q.sp2);
  search_word = q.search_word;
  return *this;
}

  ostream &print(ostream &o, const QueryResult &q)
  {
    auto n = q.sp2->size();
    o << "element occurs " << n << " times" << endl;
    auto result = *q.sp2;
    for(const auto &l : result)
      cout << "\t(sentence " << l + 1 << ") "
	   << (*q.sp1)[l] << endl;
    return o;
  }

QueryResult TextQuery::query(const string &s) const
{
  static shared_ptr<set<line_no>> nodata(new set<line_no>);
  auto iter = mp.find(s);
  auto last = mp.end();
  if(iter != last)
    return QueryResult(s, iter->second, sp1);
  else
    return QueryResult(s, nodata, sp1);
}


#endif
