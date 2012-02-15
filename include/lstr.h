/* 
 * File:   Str.h
 * Author: clement
 *
 * Created on 25 septembre 2010, 17:55
 */

#ifndef LSTR_H
#define	LSTR_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

namespace lstr
{

  int 
  toInt(const std::string& s);
  
  string 
  toString(const int n);

  int 
  wordsCount(const std::string& s);
  
  void
  erase(std::string& s, const char c);


}


#endif	/* STR_H */

