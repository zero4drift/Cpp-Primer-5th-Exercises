#include <set>
#include <string>
#include <memory>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "TextQuery.hpp"

using std::set;
using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::ostream;
using std::endl;
using std::inserter;
using std::set_intersection;
using std::string;

class Query_base
{
  friend class Query;
protected:
  using line_no = TextQuery::line_no;
  Query_base() {cout << "Query_base::Query_base()" << endl;}
  virtual ~Query_base() = default;
private:
  virtual TextQuery::QueryResult eval(const TextQuery &) const = 0;
  virtual string rep() const = 0;
};

class Query
{
  friend Query operator~(const Query &);
  friend Query operator|(const Query &, const Query &);
  friend Query operator&(const Query &, const Query &);
public:
  Query(const string &);
  TextQuery::QueryResult eval(const TextQuery &t) const {return q->eval(t);}
  string rep() const {cout << "Query::rep" << endl; return q->rep();}
private:
 Query(shared_ptr<Query_base> query): q(query) {cout << "Query::Query(shared_ptr)" << endl;}
  shared_ptr<Query_base> q;
};

class WordQuery: public Query_base
{
 public:
  friend class Query;
 WordQuery(const string &s): query_word(s) {cout << "WordQuery::WordQuery(const string &)" << endl;}
  TextQuery::QueryResult eval(const TextQuery &t) const
  {return t.query(query_word);}
  string rep() const {cout << "WordQuery::rep" << endl; return query_word;}
  string query_word;
};

inline Query::Query(const string &s): q(new WordQuery(s)) {cout << "Query::Query(const string &)" << endl;}

class BinaryQuery: public Query_base
{
 protected:
 BinaryQuery(const Query &l, const Query &r, string s):
  lhs(l), rhs(r), opSym(s) {cout << "BinaryQuery::BinaryQuery" << endl;}
  string rep() const
  {
    cout << "BinaryQuery::rep" << endl;
    return "(" + lhs.rep() + " "
      + opSym + " "
      + rhs.rep() + ")";
  }
  Query lhs, rhs;
  string opSym;
};

class AndQuery: public BinaryQuery
{
 public:
  friend Query operator&(const Query &, const Query &);
 AndQuery(const Query &left, const Query &right):
  BinaryQuery(left, right, "&") {cout << "AndQuery::AndQuery" << endl;}
  TextQuery::QueryResult eval(const TextQuery &) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
  return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

TextQuery::QueryResult
AndQuery::eval(const TextQuery &text) const
{
  auto left = lhs.eval(text), right = rhs.eval(text);
  auto ret_lines = make_shared<set<line_no>>();
  set_intersection(left.begin(), left.end(),
		  right.begin(), right.end(),
		  inserter(*ret_lines, ret_lines->begin()));
  return TextQuery::QueryResult(rep(), ret_lines, left.get_file());
}

class OrQuery: public BinaryQuery
{
 public:
  friend Query operator|(const Query &, const Query &);
 OrQuery(const Query &left, const Query &right):
  BinaryQuery(left, right, "|") {cout << "OrQUery::OrQuery" << endl;}
  TextQuery::QueryResult eval(const TextQuery &) const;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
  return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

ostream &operator<<(ostream &os, const Query &query)
{
  return os << query.rep();
}

TextQuery::QueryResult OrQuery::eval(const TextQuery &text) const
{
  auto right = rhs.eval(text), left = lhs.eval(text);
  auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
  ret_lines->insert(right.begin(), right.end());
  return TextQuery::QueryResult(rep(), ret_lines, left.get_file());
}

class NotQuery: public Query_base
{
 public:
  friend Query operator~(const Query &);
 NotQuery(const Query &q): query(q) {}
  string rep() const {return "~(" + query.rep() + ")";}
  TextQuery::QueryResult eval(const TextQuery &) const;
  Query query;
};

inline Query operator~(const Query &operand)
{
  return shared_ptr<Query_base>(new NotQuery(operand));
}

TextQuery::QueryResult
NotQuery::eval(const TextQuery &text) const
{
  auto result = query.eval(text);
  auto ret_lines = make_shared<set<line_no>>();
  auto beg = result.begin(), end = result.end();
  auto sz = result.get_file()->size();
  for(size_t n = 0; n != sz; ++n)
    {
      if(beg == end || *beg != n)
	ret_lines->insert(n);
      else if(beg != end)
	++beg;
    }
  return TextQuery::QueryResult(rep(), ret_lines, result.get_file());
}
