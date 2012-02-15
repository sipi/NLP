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
