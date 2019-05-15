//
//  util.c
//  diff
//
//  Created by William McCarthy on 5/9/19.
//  Copyright © 2019 William McCarthy. All rights reserved.
//

#include <string.h>
#include <stdlib.h>
#include "util.h"

#define BUFLEN 256

extern int showleftcolumn;
extern int suppresscommon;


char* yesorno(int condition) { return condition == 0 ? "no" : "YES"; }

FILE* openfile(const char* filename, const char* openflags) {
  FILE* f;
  if ((f = fopen(filename, openflags)) == NULL) {  printf("can't open '%s'\n", filename);  exit(1); }
  return f;
}

void printline(void) {
  for (int i = 0; i < 10; ++i) { printf("=========="); }
  printf("\n");
}


void printleft(const char* left) {
  char buf[BUFLEN];
  
  strcpy(buf, left);
  int j = 0, len = (int)strlen(buf) - 1;
  for (j = 0; j <= 48 - len ; ++j) { buf[len + j] = ' '; }
  buf[len + j++] = '<';
  buf[len + j++] = '\0';
  printf("%s\n", buf);
}

void printright(const char* right) {
  if (right == NULL) { return; }
  printf("%50s %s", ">", right);
}

void printboth(const char* left, const char* right) {
  char buf[BUFLEN];
  char bufr[BUFLEN];
  char mark = ' ';  //hey that actually worked, nice
  size_t len = strlen(left);
  if ( strcmp(left, right) != 0 ) {mark = '|';} //if the 2 lines arent equal, print the little line
  if (len > 0) { strncpy(buf, left, len); }
  buf[len - 1] = '\0'; //avoid the \n at the end of the left paragraph

  size_t lenr = strlen(right);
  if (lenr > 0) { strncpy(bufr, right, lenr); }
  bufr[lenr - 1] = '\0'; //avoid the \n at the end of the right paragraph

  //FLAG OPTIONS
  if (showleftcolumn && mark != '|') {
    bufr[0] = '\0'; //do not print the right buffer if set
    mark = '(';
  } //do not print right lines that are common

  if (suppresscommon == 0 || mark == '|') { //do not print lines that are completely commoon
    printf("%-49s%c %s\n", buf, mark, bufr);
  }
}