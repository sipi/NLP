/*  
 *  Copyright © 2011 Sipieter Clément <csipieter@gmail.com>
 *
 *  This file is part of nlp-tagger.
 *
 *  nlp-tagger is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  nlp-tagger is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with nlp-tagger.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cstdlib> 
#include <stdio.h>
#include <string> 
#include <sqlite3.h>

#include <nlplib.h>

using namespace std; 

void printhelp(int exit_code);


int 
main(int argc, char** argv, char** arge)
{  

  //********************************************************************
  // MANAGEMENT ARGUMENTS
  //********************************************************************
  
  int opt;
  bool mode_verbose = false;
  while( (opt = getopt( argc, argv, "hl:v" )) != -1 )
    {
      switch (opt)
        {
          case 'h':
            printhelp(EXIT_SUCCESS);
            break;
          case 'l':
            
            break;
          case 'v':
            mode_verbose = true;
            break;
          default:
            printhelp(EXIT_FAILURE);
        }
    }
 
  //******************************************************************
  // MAIN
  //******************************************************************
   
  char *s;
  while((s = wordtok(argv[1])) != NULL)
    {
      printf("%s\n",s);
    }
  

 /*sqlite3 *db;
  int rc; //Return value
  
  rc = sqlite3_open("nlp_tagger.db", &db);
  if( rc ){
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return(1);
  }*/

  /*rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg);
  if( rc!=SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
    }*/

  //sqlite3_close(db);
  return EXIT_SUCCESS;
  
}

void
printhelp(int exit_code)
{
  printf("\
Usage: nlp-morpho <form_src> <form_dest> [-v] [-l <code_lang>]\n\
");

  exit(exit_code);
}
