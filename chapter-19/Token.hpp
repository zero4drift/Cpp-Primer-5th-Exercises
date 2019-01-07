#ifndef TOKEN_H
#define TOKEN_H


#include <string>
#include "Sales_data.hpp"

class Token
{
 public:
 Token(): tok(INT), ival{0} {}
 Token(const Token &t): tok(t.tok) {copyUnion(t);}
 Token(Token &&t): tok(std::move(t.tok)) {moveUnion(std::move(t));}
  Token &operator=(const Token&);
  Token &operator=(Token &&);
  ~Token()
    {
      if(tok == STR) sval.~string();
      if(tok == SAL) sal.~Sales_data();
    }
  Token &operator=(const std::string&);
  Token &operator=(std::string&&);
  Token &operator=(char);
  Token &operator=(int);
  Token &operator=(double);
  Token &operator=(const Sales_data&);
  Token &operator=(Sales_data&&);
 private:
  enum {INT, CHAR, DBL, STR, SAL} tok;
  union
  {
    char cval;
    int ival;
    double dval;
    std::string sval;
    Sales_data sal;
  };
  void copyUnion(const Token&);
  void moveUnion(Token &&);
};

void Token::copyUnion(const Token &t)
{
  switch(t.tok)
    {
    case Token::INT: ival = t.ival; break;
    case Token::CHAR: cval = t.cval; break;
    case Token::DBL: dval = t.dval; break;
    case Token::STR: new(&sval) std::string(t.sval); break;
    case Token::SAL: new(&sal) Sales_data(t.sal); break;
    }
}

void Token::moveUnion(Token &&t)
{
  switch(t.tok)
    {
    case Token::INT: ival = t.ival; break;
    case Token::CHAR: cval = t.cval; break;
    case Token::DBL: dval = t.dval; break;
    case Token::STR: new(&sval) std::string(std::move(t.sval)); break;
    case Token::SAL: new(&sal) Sales_data(std::move(t.sal)); break;
    }
}

Token &Token::operator=(const Token &t)
{
  if(tok == STR && t.tok != STR) sval.~string();
  if(tok == SAL && t.tok != SAL) sal.~Sales_data();
  if(tok == STR && t.tok == STR)
    sval = t.sval;
  else if(tok == SAL && t.tok == SAL)
    sal = t.sal;
  else
    copyUnion(t);
  tok = t.tok;
  return *this;
}

  Token &Token::operator=(Token &&t)
  {
    if(this == &t) return *this;
    if(tok == STR && t.tok != STR) sval.~string();
    if(tok == SAL && t.tok != SAL) sal.~Sales_data();
    if(tok == STR && t.tok == STR)
      sval = std::move(t.sval);
    else if(tok == SAL && t.tok == SAL)
      sal = std::move(t.sal);
    else
      moveUnion(std::move(t));
    tok = std::move(t.tok);
    return *this;
  }

    Token &Token::operator=(int i)
    {
      if(tok == STR) sval.~string();
      if(tok == SAL) sal.~Sales_data();
      ival = i;
      tok = INT;
      return *this;
    }

      Token &Token::operator=(double d)
      {
	if(tok == STR) sval.~string();
	if(tok == SAL) sal.~Sales_data();
	dval = d;
	tok = DBL;
	return *this;
      }

	Token &Token::operator=(char c)
	{
	  if(tok == STR) sval.~string();
	  if(tok == SAL) sal.~Sales_data();
	  cval = c;
	  tok = CHAR;
	  return *this;
	}

	  Token &Token::operator=(const std::string &s)
	  {
	    if(tok == SAL) sal.~Sales_data();
	    if(tok == STR)
	      sval = s;
	    else
	      new(&sval) std::string(s);
	    tok = STR;
	    return *this;
	  }
	  
	    Token &Token::operator=(const Sales_data &s)
	    {
	      if(tok == STR) sval.~string();
	      if(tok == SAL)
		sal = s;
	      else
		new(&sal) Sales_data(s);
	      tok = SAL;
	      return *this;
	    }
	      
	      Token &Token::operator=(string &&s)
	      {
		if(tok == SAL) sal.~Sales_data();
		if(tok == STR)
		  sval = std::move(s);
		else
		  new(&sval) std::string(std::move(s));
		tok = STR;
		return *this;
	      }
	  
		Token &Token::operator=(Sales_data &&s)
		{
		  if(tok == STR) sval.~string();
		  if(tok == SAL)
		    sal = std::move(s);
		  else
		    new(&sal) Sales_data(std::move(s));
		  tok = SAL;
		  return *this;
		}


#endif
