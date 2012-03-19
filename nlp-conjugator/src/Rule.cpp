/*  
 *  Copyright © 2011 Sipieter Clément <csipieter@gmail.com>
 *
 *  This file is part of nlp-morpho.
 *
 *  nlp-morpho is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  nlp-morpho is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with nlp-morpho.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Rule.h"
#include "lstr.h"

Rule::Rule(const string& str_rule)
{
  char *tok = NULL;
  char *cstr = new char [str_rule.size()+1];
  strcpy (cstr, str_rule.c_str());

  string s = strtok(cstr, "->");
  lstr::erase(s, ' '); 
  this->lhs = s;

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


