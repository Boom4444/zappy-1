/*
** transtor.c for trantor in /home/liu_q//zappy/Trantor
** 
** Made by qiuyan liu
** Login   <liu_q@epitech.net>
** 
** Started on  Fri Jul  5 18:34:18 2013 qiuyan liu
** Last update Sun Jul  7 17:10:54 2013 qiuyan liu
*/

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SCREEN_WIDTH 20
#define SCREEN_HEIGHT 16
#define SCREEN_BPP 32

#define FRAMES_PER_SECOND 20

#define SQUARE_SIZE 32
#define FOOD_WIDTH 30
#define FOOD_HEIGHT 30
#define SPEED 1
#define _MOD(x,d)  (((x) < 0) ? ((d) - ( (-(x)) % (d))) : (x) % (d))

int	yVel = 0;
int	xVel = 0;

int	CURRENT_X = 0;
int	CURRENT_Y = 0;

int	MAP_WIDTH = 0;
int	MAP_HEIGHT = 0;

int	startTicks = 0;
int	pausedTicks = 0;
int	paused = 0;
int	started = 0;

SDL_Rect	clip[20];

SDL_Surface	*ressources = NULL;
SDL_Surface	*screen = NULL;

int		**map;

SDL_Event	event;

typedef struct content_square
{
  int   x;
  int   y;
  int   ressource;
}c_square;

void	clip_background()
{
  clip[0].x = SQUARE_SIZE;
  clip[0].y = SQUARE_SIZE * 2;
  clip[0].w = SQUARE_SIZE;
  clip[0].h = SQUARE_SIZE;
  /*
  clip[1].x = SQUARE_SIZE * 7;
  clip[1].y = SQUARE_SIZE * 1;
  clip[1].w = SQUARE_SIZE;
  clip[1].h = SQUARE_SIZE;

  clip[2].x = SQUARE_SIZE * 11;
  clip[2].y = SQUARE_SIZE * 1;
  clip[2].w = SQUARE_SIZE;
  clip[2].h = SQUARE_SIZE;*/
}

void	clip_plants()
{
  int	i;

  clip[3].x = SQUARE_SIZE * 2;
  clip[3].y = SQUARE_SIZE * 7;
  clip[4].x = SQUARE_SIZE * 3;
  clip[4].y = SQUARE_SIZE * 7;
  clip[5].x = SQUARE_SIZE * 3;
  clip[5].y = SQUARE_SIZE * 9;
  clip[6].x = SQUARE_SIZE * 25;
  clip[6].y = SQUARE_SIZE * 15;
  clip[7].x = SQUARE_SIZE * 25;
  clip[7].y = SQUARE_SIZE * 16;
  clip[8].x = SQUARE_SIZE * 25;
  clip[8].y = SQUARE_SIZE * 17;
  clip[9].x = SQUARE_SIZE * 25;
  clip[9].y = SQUARE_SIZE * 18;
  clip[10].x = SQUARE_SIZE * 24;
  clip[10].y = SQUARE_SIZE * 133;
  i = 2;
  while (++i < 11)
    { 
      clip[i].w = SQUARE_SIZE;
      clip[i].h = SQUARE_SIZE;
    }
}

void	clip_foods()
{
  int	i;

  clip[11].x = SQUARE_SIZE * 13 + 1;
  clip[11].y = SQUARE_SIZE * 132 + 1;
  clip[12].x = SQUARE_SIZE * 19 + 1;
  clip[12].y = SQUARE_SIZE * 132 + 1;
  clip[13].x = SQUARE_SIZE * 22  + 1;
  clip[13].y = SQUARE_SIZE * 132 + 1;
  clip[14].x = SQUARE_SIZE * 13 + 1;
  clip[14].y = SQUARE_SIZE * 134 + 1;
  clip[15].x = SQUARE_SIZE * 19 + 1;
  clip[15].y = SQUARE_SIZE * 134 + 1;
  clip[16].x = SQUARE_SIZE * 22 + 1;
  clip[16].y = SQUARE_SIZE * 134 + 1;
  clip[17].x = SQUARE_SIZE * 16 + 1;
  clip[17].y = SQUARE_SIZE * 134 + 1;
  i = 10;
  while (++i < 18)
    {
      clip[i].w = SQUARE_SIZE - 2;
      clip[i].h = SQUARE_SIZE - 2;
    }
}

void    clip_ressources()
{
  clip_background();
  clip_plants();
  clip_foods();
}

int	malloc_map(int x, int y)
{
  int	i;
  int	j;

  if (x < 1 || y < 1)
    return (0);
  else
    {
      if ((map = malloc(sizeof(int *) * y)) == NULL)
        return (0);
      j = 0;
      while (j < y)
        {
          if ((map[j] = malloc(sizeof(int) * x)) == NULL)
            {
              i = 0;
              while (i < j)
                {
                  free(map[i]);
                  i++;
                }
              free(map);
              return (0);
            }
          else
            {
              printf("line %d %p, x = %d\n",j, map[j], x);
              memset(map[j], 0, sizeof(int) * x);

              int n = 0;
              while (n < x)
		{
		  //map[j][n] = j % 3;
		  printf("%d ", map[j][n++]);
		}
              printf("\n");
            }
          j++;
        }
    }
  return (1);
}

void	make_plants()
{
  int	n;
  int	num_plants;
  int	i;
  int	j;

  num_plants = (MAP_WIDTH * MAP_HEIGHT) / 8;
  srand((unsigned)time(NULL));
  while (n < num_plants)
    {
      i = rand() % MAP_WIDTH;
      j = rand() % MAP_HEIGHT;
      map[j][i] = n % 8 + 3;
      n++;
    }
}

void	taille_carte(int x, int y)
{
  MAP_WIDTH = x;
  MAP_HEIGHT = y;
  malloc_map(x, y); 
  //  make_plants();
}

void    contenu_carte(c_square s[], int n)
{
  int   i;

  i = 0;
  while (i < n)
    {
      map[s[i].y][s[i].x] = s[i].ressource + 11;
      i++;
    }
}

void	handle_input()
{
  if( event.type == SDL_KEYDOWN )
    {
      switch( event.key.keysym.sym )
        {
	case SDLK_UP: yVel -= SPEED; break;
	case SDLK_DOWN: yVel += SPEED; break;
	case SDLK_LEFT: xVel += SPEED; break;
	case SDLK_RIGHT: xVel -= SPEED; break;
        }
    }
  else if( event.type == SDL_KEYUP )
    {
      switch( event.key.keysym.sym )
        {
	case SDLK_UP: yVel += SPEED; break;
	case SDLK_DOWN: yVel -= SPEED; break;
	case SDLK_LEFT: xVel -= SPEED; break;
	case SDLK_RIGHT: xVel += SPEED; break;
        }
    }
}

void	move()
{
  CURRENT_X = _MOD(CURRENT_X + xVel, MAP_WIDTH);
  CURRENT_Y = _MOD(CURRENT_Y + yVel, MAP_HEIGHT);
}

void	apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip )
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, clip, destination, &offset );
}



void	show_ressources()
{
  int   x;
  int   y;
  int	i;
  int	j;

  y = CURRENT_Y;
  i = 0;
  while (i < SCREEN_HEIGHT)
    {
      x = CURRENT_X;
      j = 0;
      while (j < SCREEN_WIDTH)
        {
	  apply_surface(j * SQUARE_SIZE, i * SQUARE_SIZE, ressources, screen, &clip[0]);
	  apply_surface(j * SQUARE_SIZE, i * SQUARE_SIZE, ressources, screen, &clip[map[y][x]]);
          x = _MOD(x + 1, MAP_WIDTH);
	  j++;
        }
      y = _MOD(y + 1, MAP_HEIGHT);
      i++;
    }
}


SDL_Surface	*load_image( char filename[10] )
{
    SDL_Surface*	loadedImage = NULL;
    SDL_Surface*	optimizedImage = NULL;

    loadedImage = IMG_Load( filename );
    if( loadedImage != NULL )
      {
	optimizedImage = SDL_DisplayFormat( loadedImage );
        SDL_FreeSurface( loadedImage );
	if( optimizedImage != NULL )
		SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0xFF, 0xFF, 0xFF ) );
      }
    return optimizedImage;
}



int	init()
{
  if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    return (0);
  screen = SDL_SetVideoMode( SCREEN_WIDTH * SQUARE_SIZE, SCREEN_HEIGHT * SQUARE_SIZE, SCREEN_BPP, SDL_SWSURFACE );
  if( screen == NULL )
    return (0);
  SDL_WM_SetCaption( "Trantor", NULL );
  return (1);
}

int	load_files()
{
    ressources = load_image( "res.png" );
    if( ressources == NULL)
      return (0);
    return (1);
}

void	clean_up()
{
  SDL_FreeSurface( ressources );
  SDL_Quit();
}

int	get_ticks()
{
  if (started == 1)
      if (paused == 1)
	return (pausedTicks);
      else
	return (SDL_GetTicks() - startTicks);
}

int		main( void )
{
  int		quit;
  c_square	s[10] = {{1, 0, 0}, {1, 2, 5}, {1, 4, 4}, {0, 2, 1}, {1, 0, 0}, {3, 4, 3},
                         {3, 2, 2}, {1, 0, 0}, {3, 3, 3}, {4, 4, 6}};
  quit = 0;
  if( init() == 0 )
    return 1;
  if( load_files() == 0 )
    return 1;

  taille_carte(20, 20);
  clip_ressources();
  contenu_carte(s, 10);
  while( quit == 0 )
    {
      started = 1;
      paused = 0;
      startTicks = SDL_GetTicks();
        while( SDL_PollEvent( &event ) )
        {
	  handle_input();
	  if( event.type == SDL_QUIT )
	    quit = 1;
        }
	move();
	show_ressources();
	usleep(50000);
        if( SDL_Flip( screen ) == -1 )
	  return 1;
    }

  if( get_ticks() < 1000 / FRAMES_PER_SECOND )
    SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - get_ticks() );
  clean_up();
  return 0;
}
