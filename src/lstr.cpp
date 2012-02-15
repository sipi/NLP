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

#include "lstr.h"

using namespace std;


int 
lstr::toInt(const std::string& s){
    int result=0;
    int pos_first_char=0;

    if(s[0]=='-' || s[0] == '+'){
      ++pos_first_char;
    }

    int exp=1; //exposant
    for(int i=s.length()-1; i>=pos_first_char; --i){
        result+=(s[i]-'0')*exp;
        exp*=10;
    }

    if(s[0] == '-')
      result = -result;

    return result;
}

int 
lstr::wordsCount(const std::string& s){
    int nbMot=0;
    bool posActuelIsAMot=false;
    int i;
    for(i=0; i<s.length(); ++i){
        if(posActuelIsAMot&&s[i]==' '){
            posActuelIsAMot=false;
            ++nbMot;
        }else if(!posActuelIsAMot&&s[i]!=' '){
            posActuelIsAMot=true;
        }
    }
    if(posActuelIsAMot)
        ++nbMot;

    return nbMot;
}

string 
lstr::toString(const int n){
	stringstream s;
	s << n;
	return s.str();
}

void
lstr::erase(std::string& s, const char c)
{
  string::iterator it;
  for ( it=s.begin() ; it < s.end(); it++ )
    if( *it == c )
      s.erase(it);
}


//******************************************************************************
// MAIN TEST
//******************************************************************************
/*
int main(){
    std::string s="2011565";
    std::cout << lStr::toInt(s) << std::endl;
}*/
