/*
** transtor.c for trantor in /home/liu_q//zappy/Trantor
** 
** Made by qiuyan liu
** Login   <liu_q@epitech.net>
** 
** Started on  Fri Jul  5 18:34:18 2013 qiuyan liu
** Last update Wed Jul 10 19:03:30 2013 qiuyan liu
*/

#include <unistd.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "list.h"
#include "map.h"
#include "clip_ressources.h"
#include "show_map.h"
#include "sdl_init.h"
#include "list.h"
#include "commands.h"

t_square_info	res_info[35] = {{0, 0, {0, 0, 0, 0, 1, 0, 2}},
				{1, 0, {0, 0, 1, 0, 0, 0, 1}},
				{2, 0, {0, 0, 0, 0, 0, 0, 0}},
				{3, 0, {0, 0, 1, 0, 0, 0, 0}},
				{4, 0, {0, 0, 0, 0, 0, 0, 0}},
				{5, 0, {0, 0, 0, 0, 0, 0, 0}},
				{6, 0, {0, 0, 0, 0, 0, 0, 0}},
				{0, 1, {1, 0, 0, 0, 0, 0, 0}},
				{1, 1, {0, 0, 1, 0, 0, 0, 1}},
				{2, 1, {0, 0, 0, 0, 0, 0, 0}},
				{3, 1, {0, 0, 0, 0, 1, 0, 0}},
				{4, 1, {0, 0, 0, 0, 0, 0, 0}},
				{5, 1, {0, 0, 0, 0, 0, 0, 0}},
				{6, 1, {0, 0, 0, 0, 0, 0, 0}},
				{0, 2, {0, 0, 0, 0, 0, 1, 0}},
				{1, 2, {0, 0, 1, 0, 0, 0, 0}},
				{2, 2, {0, 0, 0, 1, 0, 0, 0}},
				{3, 2, {0, 0, 0, 0, 0, 0, 0}},
				{4, 2, {0, 0, 0, 2, 0, 0, 0}},
				{5, 2, {1, 0, 0, 0, 0, 0, 0}},
				{6, 2, {0, 0, 0, 0, 0, 0, 0}},
				{0, 3, {0, 0, 0, 0, 0, 1, 0}},
				{1, 3, {0, 0, 0, 0, 0, 0, 0}},
				{2, 3, {2, 0, 0, 1, 0, 0, 0}},
				{3, 3, {0, 0, 0, 0, 0, 0, 0}},
				{4, 3, {0, 1, 0, 0, 0, 0, 0}},
				{5, 3, {0, 0, 0, 0, 0, 0, 0}},
				{6, 3, {1, 0, 0, 0, 0, 0, 0}},
				{0, 4, {1, 0, 0, 0, 0, 0, 0}},
				{1, 4, {0, 0, 0, 0, 0, 0, 1}},
				{2, 4, {0, 0, 0, 0, 0, 0, 0}},
				{3, 4, {0, 0, 0, 0, 1, 0, 0}},
				{4, 4, {0, 0, 0, 0, 0, 0, 0}},
				{5, 4, {0, 0, 1, 0, 0, 0, 0}},
				{6, 4, {0, 0, 0, 0, 0, 0, 0}}};

int		main( void )
{
  t_map		map;
  t_graphic	g;

  g.quit = 0;
  if( init(&g) == 0 || taille_carte(&map, 7, 5))
    return (1);
  contenu_carte(res_info, &map);
  while( g.quit == 0 )
    {
        while( SDL_PollEvent( &g.event ) )
        {
	  handle_input(&g);
	  if( g.event.type == SDL_QUIT )
	    g.quit = 1;
        }
	move(&map, &g);
	show_ressources(&g, &map);
	usleep(50000);
        if( SDL_Flip( g.screen ) == -1 )
	  return 1;
    }
  clean_up(&g);
  return 0;
}
