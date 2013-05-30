#include "options.h"

void    invalid_find(int argc, char *argv[])
{
  int   i;
  char  *curr;

  i = 1;
  while (i != argc)
  {
    if (*argv[i] == '-')
    {
      curr = argv[i];
      if (curr[1] != 0 && curr[1] == 'n')
      {
        while ((i + 1) != argc && *argv[i + 1] != '-')
          i++;
      }
      else
        if ((i + 1) != argc && *argv[i + 1] != '-')
          i++;
    }
    else
    {
      printf("%s: invalid option -- \"%s\"\n", argv[0], argv[i]);
      usage_display(argv[0]);
    }
    i++;
  }
}

void    the_parse(int argc, char *argv[])
{
  int   i;
  int   t;
  char  *curr;

  t = 0;
  i = 1;
  while (i != argc)
  {
    curr = argv[i];
    if (curr[0] == '-' && curr[1] != 0 && isdigit(curr[1]))
      negative_error(argv[0], argv[i]);
    if (curr[t] == '-' && curr[t + 1] == 0)
      syntax_error(argv[0], argv[i]);
    while (curr[t] != 0)
    {
      if (curr[t] == 10)
        lparse_error_1(argv[0]);
      if (isalnum(curr[t]) == 0 && curr[t] != '-' && curr[t] != '_')
        lparse_error_2(argv[0], argv[i]);
      t++;
    }
    t = 0;
    i++;
  }
}

int     get_nbrlen(int nbr)
{
  int   i;

  i = 0;
  while (nbr != 0)
  {
    nbr /= 10;
    i++;
  }
  return (i);
}

void    teams_fill(t_opt *opt)
{
  int   i;
  char  *tmp;
  int   size;

  tmp = NULL;
  i = opt->names->len;
  while (i < opt->cmax)
  {
    i++;
    size = get_nbrlen(i) + 6;
    if ((tmp = realloc(tmp, size)) == NULL)
    {
      printf("%s error: %s\n", "realloc", strerror(errno));
      exit(-1);
    }
    sprintf(tmp, "Team_%d", i);
    list_add_back(opt->names, tmp, size);
  }
  free(tmp);
}