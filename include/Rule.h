#ifndef _RULE_H_
#define _RULE_H_

#include <string>
#include <vector>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

class Rule
{
 public :
  Rule(const string &rule);
  string str();
 
  regex lhs;
  vector<string> rhs;
};

#endif
