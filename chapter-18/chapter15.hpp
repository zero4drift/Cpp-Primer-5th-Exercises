#ifndef CHAPTER15_H
#define CHAPTER15_H


#include <set>
#include <string>
#include <memory>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "chapter10.hpp"

using std::set;
using std::cout;
using std::ostream;
using std::endl;
using std::inserter;
using std::set_intersection;
using std::string;

namespace chapter15
{
  class Query_base
  {
    friend class Query;
  protected:
    using line_no = chapter10::TextQuery::line_no;
    Query_base() {}
    virtual ~Query_base() = default;
  private:
    virtual chapter10::QueryResult eval(const chapter10::TextQuery &) const = 0;
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
    chapter10::QueryResult eval(const chapter10::TextQuery &t) const {return q->eval(t);}
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
    chapter10::QueryResult eval(const chapter10::TextQuery &t) const
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
    chapter10::QueryResult eval(const chapter10::TextQuery &) const;
  };

  inline Query operator&(const Query &lhs, const Query &rhs)
  {
    return new AndQuery(lhs, rhs);
  }

  chapter10::QueryResult
    AndQuery::eval(const chapter10::TextQuery &text) const
  {
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    set_intersection(left.begin(), left.end(),
		     right.begin(), right.end(),
		     inserter(*ret_lines, ret_lines->begin()));
    return chapter10::QueryResult(rep(), ret_lines, left.get_file());
  }

  class OrQuery: public BinaryQuery
  {
    friend Query operator|(const Query &, const Query &);
  OrQuery(const Query &left, const Query &right):
    BinaryQuery(left, right, "|") {}
    chapter10::QueryResult eval(const chapter10::TextQuery &) const;
  };

  inline Query operator|(const Query &lhs, const Query &rhs)
  {
    return new OrQuery(lhs, rhs);
  }

  ostream &operator<<(ostream &os, const Query &query)
    {
      return os << query.rep();
    }

  chapter10::QueryResult OrQuery::eval(const chapter10::TextQuery &text) const
  {
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return chapter10::QueryResult(rep(), ret_lines, left.get_file());
  }

  class NotQuery: public Query_base
  {
    friend Query operator~(const Query &);
  NotQuery(const Query &q): query(q) {}
    string rep() const {return "~(" + query.rep() + ")";}
    chapter10::QueryResult eval(const chapter10::TextQuery &) const;
    Query query;
  };

  inline Query operator~(const Query &operand)
  {
    return new NotQuery(operand);
  }

  chapter10::QueryResult
    NotQuery::eval(const chapter10::TextQuery &text) const
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
    return chapter10::QueryResult(rep(), ret_lines, result.get_file());
  }
}


#endif
