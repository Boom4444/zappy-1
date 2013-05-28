#include <unistd.h> // getopt
#include <string.h> // strlen
#include <stdio.h> // printf
#include "options.h"

void  options_get(char *argv[], char c, int *opt)
{
  char  *curr;

  if (*optarg == '-')
  {
    printf("%s: option requires an argument -- '%c'\n", argv[0], c);
    usage_display(argv[0]);
  }
  *opt = atoi(optarg);
  if (optarg[0] != 48 && *opt == 0)
  {
    curr = argv[optind - 1];
    if (curr[1] != 0)
    {
      printf("%s: invalid option -- \"%s\"\n", argv[0], curr);
      usage_display(argv[0]);
    }
    printf("%s: invalid argument -- \'%c'\n", argv[0], c);
    usage_display(argv[0]);
  }
}

void  names_parse(char *argv[], char c, int argc, t_opt *opt)
{
  if (*optarg == '-')
  {
    printf("%s: option requires an argument -- '%c'\n", argv[0], c);
    usage_display(argv[0]);
  }
  optind--;
  while ((optind < argc) && (*argv[optind] != '-'))
  {
    list_add_back(opt->names, argv[optind], strlen(argv[optind]));
    optind++;
  }
}

void  invalid_find(int argc, char *argv[])
{
  int   i = 1;
  char  *curr;

  while (i < argc)
  {
    if (*argv[i] == '-')
    {
      curr = argv[i];
      if (curr[1] == 'n')
      {
        while (*argv[i + 1] != '-' && i < argc)
          i++;
      }
      else
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

void  default_error(int argc, char *argv[])
{
  int   i = 1;
  char  *curr = argv[optind - 1];

  if (optopt == curr[1])
  {
    printf("%s: invalid option -- \"%s\"\n", argv[0], argv[optind - 1]);
    usage_display(argv[0]);
  }
  else
  {
    printf("%s: invalid option -- \"%s\"\n", argv[0], argv[optind]);
    usage_display(argv[0]);
  }
}

void  options_parse(int argc, char *argv[], t_opt *g_opt)
{
  int   l_opt;

  invalid_find(argc, argv);
  opterr = 0;
  while ((l_opt = getopt(argc, argv, "p:x:y:n:c:t:")) != -1)
  {
    if (l_opt == 'p')
      options_get(argv, l_opt, &g_opt->port);
    if (l_opt == 'x')
      options_get(argv, l_opt, &g_opt->width);
    if (l_opt == 'y')
      options_get(argv, l_opt, &g_opt->height);
    if (l_opt == 'n')
      names_parse(argv, l_opt, argc, g_opt);     
    if (l_opt == 'c')
      options_get(argv, l_opt, &g_opt->nclients);
    if (l_opt == 't')
      options_get(argv, l_opt, &g_opt->tdelay);
    if (l_opt == '?')
      default_error(argc, argv);
  }
}