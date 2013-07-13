/*
** broadcast.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Mon Jul 01 14:23:40 2013 Marin Alcaraz
** Last update Sat Jul 13 18:18:14 2013 ivan ignatiev
*/

#include	<math.h>
#include	"main.h"
#include	"list.h"
#include	"options.h"
#include	"trantor.h"
#include	"server.h"
#include	"users.h"
#include	"request.h"
#include	"proto_commands_movement.h"
#include	"answer.h"

static double	g_offsets[9][2]=
  {
    {-1.0, -1.0},
    {0.0, -1.0},
    {1.0, -1.0},
    {-1.0, 0.0},
    {0.0, 0.0},
    {1.0, 1.0},
    {-1.0, 1.0},
    {0.0, 1.0},
    {1.0, 1.0}
  };

int		determine_direction(int alpha)
{
  if (alpha <= 22.5 || alpha >= 337.5)
    return (MID_RIGHT);
  else if (alpha < 67.5 && alpha > 22.5 )
    return (BOT_RIGHT);
  else if (alpha >= 67.5 && alpha <= 112.5)
    return (BOT_MID);
  else if (alpha > 112.5 && alpha < 157.5)
    return (BOT_LEFT);
  else if (alpha >= 157.5 && alpha <= 202.5)
    return (MID_LEFT);
  else if (alpha > 202.5 && alpha < 247.5)
    return (TOP_LEFT);
  else if (alpha >= 247.5 && alpha <= 292.5)
    return (TOP);
  else if (alpha > 292.5 && alpha < 337.5)
    return (TOP_RIGHT);
  return (-1);
}

double		broadcast_get_distance(t_user_player *u,
				       int x, int y)
{
  return (sqrt(pow((u->posx - x), 2) + pow((u->posy - y), 2)));
}

int		or_to_dir(int orientation)
{
  if (orientation == NORTH)
    return (TOP);
  if (orientation == EAST)
    return (MID_RIGHT);
  if (orientation ==SOUTH)
    return (BOT_MID);
    if (orientation == WEST)
      return (MID_LEFT);
    return (orientation);
}

double		generate_offsets(double offsets[9][3],
				 t_request_data  *rqd,
				 t_user_player *current, t_server *t)
{
  int		i;
  int		mini;
  double	rad;

  i = 0;
  mini = 0;
  while (i < 9)
    {
      offsets[i][0] = (g_offsets[i][0] * t->options.width)
	+ current->posx;
      offsets[i][1] = (g_offsets[i][1] * t->options.height)
	+ current->posy;
      offsets[i][2] = broadcast_get_distance(rqd->user, offsets[i][0],
					     offsets[i][1]);
      if (offsets[mini][2] > offsets[i][2])
	mini = i;
      i = i + 1;
    }
  rad = atan2((1.0 * rqd->user->posy - offsets[mini][1]),
	      (1.0 * rqd->user->posx - offsets[mini][0]));
  if (rad >= -0.000001 && rad <= 0.000001
      && rqd->user->posx < offsets[mini][0])
    rad = rad + M_PI;
  rad = rad < 0 ? rad + (2 * M_PI) : rad;
  return ((180.0 * rad) / M_PI);
}

int		broadcast_to(t_user_player *user, t_request_data *rqd,
			     t_server *t)
{
  double	alpha;
  double	point_data[9][3];
  int		direction;

  alpha = generate_offsets(point_data, rqd, user, t);
  direction = determine_direction(alpha);
  direction = (8 - or_to_dir(user->orientation) + direction) % 8;
  return (direction);
}
