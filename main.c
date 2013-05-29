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
  t_opt g_opt;
  
  server_settings_init(&g_opt);
  options_parse(argc, argv, &g_opt);

  printf("\n-p=%d, -x=%d, -y=%d, -c=%d, -t=%d\n", 
    g_opt.port, g_opt.width, g_opt.height, g_opt.nclients, g_opt.tdelay);
  printf("Teams (%d):\n", g_opt.names->len);
  list_iter(g_opt.names, &dump_string);
  printf("\n");
  // dis salad is for test printing ^

  delete_list(g_opt.names);
  return (1);
}