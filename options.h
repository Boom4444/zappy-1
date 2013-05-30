#ifndef MAIN_H_
# define MAIN_H_

#include "list.h"
#include <unistd.h> // getopt
#include <string.h> // strlen
#include <stdio.h> // printf
#include <stdlib.h> // malloc
#include <ctype.h> // isalnum
#include <errno.h> // errno

typedef struct  s_options 
{
  int           port; // -p
  int           width; // -x
  int           height; // -y
  t_list        *names; // -n
  int           cmax; // -c
  int           tdelay; // -t
}               t_opt;

#endif /* MAIN_H_ */