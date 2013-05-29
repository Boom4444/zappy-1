#include "options.h"

void  negative_error(char *str, char *ptr)
{
  printf("%s: illegal characters -- \"%s\"\n", str, ptr);
  printf("Argument values can only be positive.\n");
  exit(-1);
}

void  eagle_error(int argc, char *argv[])
{
  printf("%s: option requires an argument -- '%c'\n", argv[0], optopt);
  usage_display(argv[0]);
}

void  lparse_error_1(char *str)
{
  printf("%s: illegal characters -- \'\\n\'\n", str);
  printf("Server args and options can contain only letters");
  printf(" and numbers (+ '-', '_' characters).\n");
  exit(-1);
}

void  lparse_error_2(char *str, char *ptr)
{
  printf("%s: illegal characters -- '%s'\n", str, ptr);
  printf("Server args and options can contain only letters");
  printf(" and numbers (+ '-', '_' characters).\n");
  exit(-1);
}

void  syntax_error(char *str, char *ptr)
{
  printf("%s: syntax error -- '%s'\n", str, ptr);
  usage_display(str);
}
