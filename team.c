/*
** team.c for zappy in /home/ignati_i//zappy/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Jul 13 12:19:50 2013 ivan ignatiev
** Last update Sun Jul 14 21:29:20 2013 ivan ignatiev
*/

#include	"main.h"
#include	"list.h"
#include	"options.h"
#include	"trantor.h"
#include	"server.h"
#include	"users.h"
#include	"error.h"
#include	"item.h"
#include	"answer.h"

t_team		*team_create(char *name, t_server *s)
{
  t_team	*team;

  if ((team = (t_team*)malloc(sizeof(t_team))) != NULL)
    {
      strncpy(team->name, name, NAME_LIMIT);
      team->name[NAME_LIMIT] = '\0';
      team->members = 0;
      team->limit = s->options.cmax;
      team->v_flag = 0;
      log_show("team_create", "", "Team created : '%s'", team->name);
    }
  return (team);
}

t_team		*team_search(t_list *team_list, char *team_name)
{
  t_item	*current;

  current = list_get_head(team_list);
  while (current != NULL)
    {
      if (strcmp(T_TEAM(current)->name, team_name) == 0)
	return (T_TEAM(current));
      current = current->next;
    }
  return (NULL);
}

t_list		*team_list_init(t_server *s, t_list *team_names)
{
  t_team	*team;
  t_item	*current;

  s->team_list = list_init();
  current = list_get_head(team_names);
  while (current != NULL)
    {
      team = team_create((char*)(current->cont), s);
      item_pf(s->team_list, (void*)team, sizeof(t_team));
      current = current->next;
    }
  return (s->team_list);
}
