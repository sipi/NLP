/*  
 *  Copyright © 2011 Sipieter Clément <csipieter@gmail.com>
 *
 *  This file is part of nlplib.
 *
 *  nlplib is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  nlplib is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with nlplib.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string.h>
#include "nlplib.h"


char *wordtok(char *str)
{
  return strtok(str, " ");
}

