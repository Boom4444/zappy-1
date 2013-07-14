/*
** proto_commands_res.c for zappy in /home/ignati_i//zappy/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Jul 13 20:17:33 2013 ivan ignatiev
** Last update Sun Jul 14 14:10:27 2013 ivan ignatiev
*/

#include	"main.h"
#include	"list.h"
#include	"options.h"
#include	"trantor.h"
#include	"server.h"
#include	"users.h"
#include	"request.h"
#include	"answer.h"
#include	"item.h"
#include	"proto_commands_movement.h"
#include	"str.h"

static char	*g_objects[] =
  {
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame"
  };

int		match_index(char *str)
{
  int		i;

  if (is_numeric(str))
    return (atoi(str));
  i = 0;
  while (i < RES_TYPES_COUNT)
    {
      if (strcmp(g_objects[i], str) == 0)
	return (i);
      i = i + 1;
    }
  return (-1);
}

char		*cli_voir_players(char *response, t_list *players)
{
  t_item	*current;

  current = list_get_head(players);
  while (current != NULL)
    {
      response = stralloccat(response, " player");
      current = current->next;
    }
  return (response);
}

char		*cli_voir_resources(char *response, int *resources)
{
  int		i;
  int		j;

  i = 0;
  while (i < RES_TYPES_COUNT)
    {
        j = 0;
        while (j < resources[i])
	  {
            response = stralloccat(response, " ");
            response = stralloccat(response, g_objects[i]);
            j++;
	  }
        i = i + 1;
    }
  response = stralloccat(response, ",");
  return (response);
}
