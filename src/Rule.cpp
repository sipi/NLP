#include "Rule.h"

Rule::Rule(const string& str_rule)
{
  char *tok = NULL;
  char *cstr = new char [str_rule.size()+1];
  strcpy (cstr, str_rule.c_str());

  this->lhs = strtok(cstr, "->");

  tok = strtok(NULL, "|");
  this->rhs.push_back(tok + 1);

  while ( (tok = strtok(NULL, "|")) != NULL )
  {
      this->rhs.push_back(tok); 
  }
}


string
Rule::str()
{
  vector<string>::iterator it;
  string s = this->lhs.str() + string(" -> ");
  
  for(it = this->rhs.begin(); it < this->rhs.end(); it++)
    {
      s += *it;
      s += " | ";
    }
    
  s.erase(s.size()-3, 3) ;


  return s;
}


