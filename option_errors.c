#include "options.h"

void  negative_error(char *str, char *ptr)
{
  printf("%s: illegal characters -- \"%s\"\n", str, ptr);
  printf("Argument values can only be positive.\n");
  exit(EXIT_SUCCESS);
}

void  eagle_error(char *str)
{
  printf("%s: option requires an argument -- '%c'\n", str, optopt);
  usage_display(str);
}

void  lparse_error_1(char *str)
{
  printf("%s: illegal characters -- \'\\n\'\n", str);
  printf("Server options should contain only '-' combined with a letter.\n");
  printf("Server argumens can contain only letters");
  printf(" and numbers (+ ' ' '_' characters).\n");
  exit(EXIT_SUCCESS);
  
}

void  lparse_error_2(char *str, char c)
{
  printf("%s: illegal characters -- '%c'\n", str, c);
  printf("Server options should contain only '-' combined with a letter.\n");
  printf("Server argumens can contain only letters");
  printf(" and numbers (+ ' ' '_' characters).\n");
  exit(EXIT_SUCCESS);
}

void  syntax_error(char *str, char *ptr)
{
  printf("%s: syntax error -- '%s'\n", str, ptr);
  usage_display(str);
}
