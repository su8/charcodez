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

#define STREQ(x, z) (0 == (strcmp(x, z)))

int main(int argc, char *argv[]) {
  int x = 2, to_base = 10;
  char *from_base = NULL;

  if (1 == argc || 2 == argc) {
    puts("usage: charcodez hex 0xdeadbeef");
    return EXIT_FAILURE;
  }
  from_base = argv[1];

  if (STREQ("binary",  from_base)) {to_base = 2;  goto run_it;}
  if (STREQ("octal",   from_base)) {to_base = 8;  goto run_it;}
  if (STREQ("decimal", from_base)) {to_base = 10; goto run_it;}
  if (STREQ("hex",     from_base)) {to_base = 16; goto run_it;}
  if (STREQ("36",      from_base)) {to_base = 36;}

run_it:
  for (; x < argc; x++) {
    printf("%lld\n", strtoll(argv[x], (char **)NULL, to_base));
  }

  return EXIT_SUCCESS;
}
