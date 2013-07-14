/*
** graph_utils.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Fri Jul 12 22:31:08 2013 Marin Alcaraz
** Last update Sun Jul 14 12:54:48 2013 ivan ignatiev
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
  int		i;
  int		j;
  int		min;
  char		bct_line[STR_LIMIT];

  j = 0;
  while (j < w->height)
    {
      i = 0;
      while (i < w->width)
        {
	  sprintf(bct_line, "bct %d %d", i, j);
	  response = stralloccat(response, bct_line);
	  min = 0;
	  while (min < RES_TYPES_COUNT)
            {
	      sprintf(bct_line, " %d",
		      w->surface[j][i].resources[min++]);
	      response = stralloccat(response, bct_line);
            }
	  i = i + 1;
	  response = stralloccat(response, "\n");
        }
      cli_answer_to_graph(rqd->user, response);
      *response = '\0';
      j = j + 1;
    }
}
