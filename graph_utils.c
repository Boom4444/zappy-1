/*
** graph_utils.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Fri Jul 12 22:31:08 2013 Marin Alcaraz
** Last update Fri Jul 12 22:31:56 2013 Marin Alcaraz
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
#include	"graph_command.h"
#include	"users_graph.h"

int		get_content(int *info, char *response, t_world *w)
{
    int		i;
    char	aux_response[STR_LIMIT];

    while (i < 7)
    {
        sprintf(aux_response, " %d",
                w->surface[info[1]][info[0]].resources[i]);
        strcat(response, aux_response);
        aux_response[0] = '\0';
        i = i + 1;
    }
    return (0);
}

void	parse_and_answer(char *response,
			 t_graph_data *rqd, t_world *w)
{
  int	indexes[3];
  char	bct_line[STR_LIMIT];

  indexes[0] = 0;
  while (indexes[0] < w->height)
    {
      indexes[1] = 0;
      while (indexes[1] < w->width)
        {
	  sprintf(response, "bct %d %d", indexes[1], indexes[0]);
	  indexes[2] = 0;
	  while (indexes[3] < RES_TYPES_COUNT)
            {
	      sprintf(bct_line, " %d",
		      w->surface[indexes[0]][indexes[1]].
		      resources[indexes[2]++]);
	      strcat(response, bct_line);
            }
	  indexes[1] = indexes[1] + 1;
	  strcat(response, "\n");
	  cli_answer_to_graph(rqd->user, response);
        }
      indexes[0] = indexes[0] + 1;
      response[0] = '\0';
    }
}
