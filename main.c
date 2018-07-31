/*
   07/31/2018
 
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
 
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
 
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STREQ(x, z) (0 == (strcmp(x, z)))

int main(int argc, char *argv[]) {
  int x = 2, base = 10;
  char *from_base = NULL;

  if (1 == argc || 2 == argc) {
    puts("usage: charcodez hex 0xdeadbeef");
    return EXIT_FAILURE;
  }
  from_base = argv[1];

  for (; x < argc; x++) {
    if (STREQ("binary",  from_base)) base = 2;
    if (STREQ("octal",   from_base)) base = 8;
    if (STREQ("decimal", from_base)) base = 10;
    if (STREQ("hex",     from_base)) base = 16;
    if (STREQ("36",      from_base)) base = 36;

    printf("%lld\n", strtoll(argv[x], (char **)NULL, base));
  }

  return EXIT_SUCCESS;
}
