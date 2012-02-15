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
 
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <boost/regex.hpp>
#include <vector>


#include "Rule.h"
#include "lstr.h"

using namespace boost;
using namespace std;



int 
main(int argc, char** argv, char** arge)
{
  
  //********************************************************************
  // GESTION DES OPTIONS
  //********************************************************************
  
  string str_lang("en_US");
  regex rx_lang("^LANG=(.*)\\..*$");
  
  int i = -1;
  while(arge[++i] != NULL)
    if(regex_match(arge[i], rx_lang))
      str_lang = regex_replace(string(arge[i++]), rx_lang, "\\1");
  
  
  int opt;
  bool mode_verbose = false;
  while( (opt = getopt( argc, argv, "bl:v" )) != -1 )
  {
    switch (opt)
    {
      case 'b':
        printf("b\n");
        break;
      case 'l':
        str_lang = optarg;
        break;
      case 'v':
        mode_verbose = true;
        break;
      default:
        fprintf(stderr,"bad option\n", argv[0]);
        exit(EXIT_FAILURE);
    }
  }
  
  if(mode_verbose)
    printf("str_lang : %s\n", str_lang.c_str());
    
  str_lang = string("./lang/")+str_lang+ string(".lang");
  
  //********************************************************************
  // MAIN
  //********************************************************************
  
  //********************************************************************
  // CHARGEMENT DES REGLES
  
  FILE *fp = NULL;
  char* line = NULL;
  size_t len = 0;
  string s;
  vector<Rule> rules;
  
  fp = fopen(str_lang.c_str(), "r");
  if(fp == NULL)
    return -1;
  
 
  while(getline(&line, &len, fp) != -1)
    {
      regex rx_rule("^.*->.*$");
      line[strlen(line) - 1] = ' '; //suppression du \n de fin de ligne
      s = line; 
      s = s.substr(0,s.find('#')); //suppression des commentaires

      if(regex_match(s, rx_rule))
      {
        lstr::erase(s, ' '); 
        rules.push_back(Rule(s));
      }
    }
  
  
  //********************************************************************
  // MAIN LOOP
  
  char cstring[256];
  string str, new_str;
  
  while(scanf("%s", cstring) != EOF)
  {
    str = cstring;
    
    vector<Rule>::iterator it;
    for( it = rules.begin(); it < rules.end(); it++ )
    {
      if( regex_match(str, it->lhs) )
      {
        vector<string>::iterator it_str;
        for( it_str = it->rhs.begin(); it_str < it->rhs.end(); it_str++ )
        {
          new_str = regex_replace(str, it->lhs, *it_str);
          
          printf("%s", new_str.c_str());
          if(mode_verbose)
            printf(" (%s)", it->str().c_str());
            
          printf("\n");
          
        }
        break;
      }
    }
  }
  
  return 0;
}
