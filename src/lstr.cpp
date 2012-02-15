/* 
 * File:   Str.cpp
 * Author: clement
 * 
 * Created on 25 septembre 2010, 17:55
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
