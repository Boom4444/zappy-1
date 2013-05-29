#include <stdio.h> // printf
#include "options.h"

static void dump_string(void *content, int size) // for test
{
  printf(" %s\n", (char*)content);
}

void    server_settings_init(t_opt *opt)
{
  opt->port = 0; 
  opt->width = 0; 
  opt->height = 0; 
  opt->nclients = 0; 
  opt->tdelay = 0;
  opt->names = new_list_by_default();
}

int     main(int argc, char *argv[])
{
  t_opt option;
  
  server_settings_init(&option);
  options_parse(argc, argv, &option);

  printf("\n-p=%d, -x=%d, -y=%d, -c=%d, -t=%d\n", 
    option.port, option.width, option.height, option.nclients, option.tdelay);
  printf("Teams (%d):\n", option.names->len);
  list_iter(option.names, &dump_string);
  printf("\n");
  // dis salad is for test printing ^

  delete_list(option.names);
  return (1);
}