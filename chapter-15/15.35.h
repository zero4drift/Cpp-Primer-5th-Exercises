#include <string>
#include <memory>
#include <iostream>
#include "TextQuery.h"

using std::shared_ptr;
using std::cout;
using std::ostream;
using std::endl;
using std::string;

class Query_base
{
  friend class Query;
protected:
  using line_no = TextQuery::line_no;
  Query_base() {cout << "Query_base::Query_base()" << endl;}
  virtual ~Query_base() = default;
private:
  // virtual QueryResult eval(const TextQuery &) const = 0;
  virtual string rep() const = 0;
};

class Query
{
  friend Query operator~(const Query &);
  friend Query operator|(const Query &, const Query &);
  friend Query operator&(const Query &, const Query &);
public:
  Query(const string &);
  // QueryResult eval(const TextQuery &t) const {return q->eval(t);}
  string rep() const {cout << "Query::rep" << endl; return q->rep();}
private:
 Query(shared_ptr<Query_base> query): q(query) {cout << "Query::Query(shared_ptr)" << endl;}
  shared_ptr<Query_base> q;
};

class WordQuery: public Query_base
{
  friend class Query;
 WordQuery(const string &s): query_word(s) {cout << "WordQuery::WordQuery(const string &)" << endl;}
  // QueryResult eval(const TextQuery &t) const
  // {return t.query(query_word);}
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
  friend Query operator&(const Query &, const Query &);
 AndQuery(const Query &left, const Query &right):
  BinaryQuery(left, right, "&") {cout << "AndQuery::AndQuery" << endl;}
  // QueryResult eval(const TextQuery &) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
  return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery: public BinaryQuery
{
  friend Query operator|(const Query &, const Query &);
 OrQuery(const Query &left, const Query &right):
  BinaryQuery(left, right, "|") {cout << "OrQUery::OrQuery" << endl;}
  // QueryResult eval(const TextQuery &) const;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
  return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

ostream &operator<<(ostream &os, const Query &query)
{
  return os << query.rep();
}
