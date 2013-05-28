#include "options.h"

void    negative_parse(int argc, char *argv[])
{
  int   i;
  char  *curr;

  i = 1;
  while (i != argc)
  {
    curr = argv[i];
    if (curr[0] == '-' && curr[1] != 0 && isdigit(curr[1]))
    {
      printf("%s: illegal characters -- \"%s\"\n", argv[0], argv[i]);
      printf("Argument values can only be positive.\n");
      exit(1);
    }
    i++;
  }
}

void    names_parse(char *argv[], char c, int argc, t_opt *opt)
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

void    lparse_error_1(char *str)
{
  printf("%s: illegal characters -- \'\\n\'\n", str);
  printf("Server args and options can contain only letters");
  printf(" and numbers (+ '-', '_' characters).\n");
  exit(1);
}

void    lparse_error_2(char *str, char *ptr)
{
  printf("%s: illegal characters -- '%s'\n", str, ptr);
  printf("Server args and options can contain only letters");
  printf(" and numbers (+ '-', '_' characters).\n");
  exit(1);
}

void    letters_parse(int argc, char *argv[])
{
  int   i;
  int   t;
  char  *curr;

  t = 0;
  i = 1;
  while (i != argc)
  {
    curr = argv[i];
    while (curr[t] != 0)
    {
      if (curr[t] == '-' && curr[t + 1] == 0)
      {
        printf("%s: syntax error -- '%s'\n", argv[0], argv[i]);
        usage_display(argv[0]);
      }
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
