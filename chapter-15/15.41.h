#include <set>
#include <string>
#include <memory>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "TextQuery.hpp"

using std::set;
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
  Query_base() {}
  virtual ~Query_base() = default;
private:
  virtual QueryResult eval(const TextQuery &) const = 0;
  virtual string rep() const = 0;
};

class Query
{
  friend Query operator~(const Query &);
  friend Query operator|(const Query &, const Query &);
  friend Query operator&(const Query &, const Query &);
public:
  Query(const string &);
  Query(const Query &p): q(p.q), use(p.use) {++*use;}
  Query &operator=(const Query &p);
  QueryResult eval(const TextQuery &t) const {return q->eval(t);}
  string rep() const {return q->rep();}
  ~Query()
  {
    if(--*use == 0)
      {
	delete q;
	delete use;
      }
  }
private:
 Query(Query_base *query): q(query), use(new unsigned(1)) {}
  Query_base *q;
  unsigned *use;
};

Query &Query::operator=(const Query &p)
{
  ++*p.use;
  if(--*use == 0)
    {
      delete use;
      delete q;
    }
  use = p.use;
  q = p.q;
  return *this; 
}

class WordQuery: public Query_base
{
  friend class Query;
  WordQuery(const string &s): query_word(s) {}
  QueryResult eval(const TextQuery &t) const
  {return t.query(query_word);}
  string rep() const {return query_word;}
  string query_word;
};

inline Query::Query(const string &s): q(new WordQuery(s)), use(new unsigned(1)) {}

class BinaryQuery: public Query_base
{
protected:
  BinaryQuery(const Query &l, const Query &r, string s):
    lhs(l), rhs(r), opSym(s) {}
  string rep() const
  {
    return "(" + lhs.rep() + " "
      + opSym + " "
      + rhs.rep() + ")";
  }
  Query lhs, rhs;
  string opSym;
};

class AndQuery: public BinaryQuery
{
  friend Query operator&(const Query &, const Query &);
  AndQuery(const Query &left, const Query &right):
    BinaryQuery(left, right, "&") {}
  QueryResult eval(const TextQuery &) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
  return new AndQuery(lhs, rhs);
}

QueryResult
AndQuery::eval(const TextQuery &text) const
{
  auto left = lhs.eval(text), right = rhs.eval(text);
  auto ret_lines = make_shared<set<line_no>>();
  set_intersection(left.begin(), left.end(),
		   right.begin(), right.end(),
		   inserter(*ret_lines, ret_lines->begin()));
  return QueryResult(rep(), ret_lines, left.get_file());
}

class OrQuery: public BinaryQuery
{
  friend Query operator|(const Query &, const Query &);
  OrQuery(const Query &left, const Query &right):
    BinaryQuery(left, right, "|") {}
  QueryResult eval(const TextQuery &) const;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
  return new OrQuery(lhs, rhs);
}

ostream &operator<<(ostream &os, const Query &query)
{
  return os << query.rep();
}

QueryResult OrQuery::eval(const TextQuery &text) const
{
  auto right = rhs.eval(text), left = lhs.eval(text);
  auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
  ret_lines->insert(right.begin(), right.end());
  return QueryResult(rep(), ret_lines, left.get_file());
}

class NotQuery: public Query_base
{
  friend Query operator~(const Query &);
  NotQuery(const Query &q): query(q) {}
  string rep() const {return "~(" + query.rep() + ")";}
  QueryResult eval(const TextQuery &) const;
  Query query;
};

inline Query operator~(const Query &operand)
{
  return new NotQuery(operand);
}

QueryResult
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
  return QueryResult(rep(), ret_lines, result.get_file());
}
