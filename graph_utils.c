/*
** graph_utils.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Fri Jul 12 22:31:08 2013 Marin Alcaraz
** Last update Sun Jul 14 07:32:28 2013 Marin Alcaraz
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
#include	"str.h"

int		get_content(int *info, char *response,
			    t_world *w)
{
  int		i;
  char		aux_response[STR_LIMIT];

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

void		parse_and_answer(char *response, t_graph_data *rqd,
				 t_world *w)
{
  int		is[3];
  char		bct_line[STR_LIMIT];

  is[0] = 0;
  while (is[0] < w->height)
    {
      is[1] = 0;
      while (is[1] < w->width)
        {
	  sprintf(bct_line, "bct %d %d", is[1], is[0]);
	  response = stralloccat(response, bct_line);
	  is[2] = 0;
	  while (is[2] < RES_TYPES_COUNT)
            {
	      sprintf(bct_line, " %d",
		      w->surface[is[0]][is[1]].resources[is[2]++]);
	      response = stralloccat(response, bct_line);
            }
	  is[1] = is[1] + 1;
	  response = stralloccat(response, "\n");
        }
      cli_answer_to_graph(rqd->user, response);
      *response = '\0';
      is[0] = is[0] + 1;
    }
}
