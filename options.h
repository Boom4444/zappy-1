#ifndef MAIN_H_
 #define MAIN_H_

# include "list.h"

typedef struct  s_options 
{
  int     port; // -p
  int     width; // -x
  int     height; // -y
  t_list  *names; // -n
  int     nclients; // -c
  int     tdelay; // -t
} t_opt;

#endif