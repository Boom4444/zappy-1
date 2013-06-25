/*
** trantor.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 20 17:33:58 2013 Marin Alcaraz
** Last update Tue Jun 25 17:17:14 2013 Marin Alcaraz
*/

#include    "trantor.h"

int        init_world(t_world *w, int width, int height)
{
    int      i;

    i = 0;
    w->surface = (t_square_unit **) malloc(sizeof(t_square_unit *) * height);
    while (i < height)
    {
        if ((w->surface[i] = malloc(sizeof(t_square_unit) * width)) == NULL)
        {
            error_show("init_world", "init_world", "Error: can't allocate (width) game board\n");
            return (EXIT_FAILURE);
        }
        i = i + 1;
    }
    return (0);
}

int     mineral_checker(t_square_unit sq)
{
    int     i;

    i = 0;
    while (i < 6)
    {
        if (sq.resources[i] != 0)
            return (1);
        i = i + 1;
    }
    return (0);
}

int          display_world(t_world *w, int width, int height)
{
    int      i;
    int      j;

    i = 0;
    j = 0;
    while (i < height)
    {
        while (j < width)
        {
            if (mineral_checker(w->surface[i][j]) != 0)
                printf("M");
            else
                printf("*");
            j = j + 1;
        }
        printf("\n");
        i = i + 1;
        j = 0;
    }
    return (0);
}

void        random_number(int *container, int limit)
{
    srand(time(NULL));
    *container = rand() % limit;
}

int         generate_resource(t_world *w, int width, int height)
{
    int     minx;
    int     miny;
    int     resource;

    random_number(&minx, width);
    random_number(&miny, height);
    random_number(&resource, 7);
    (w->surface[miny][minx]).resources[resource]++;
    printf("Generated on x[%d] y[%d] the mineral[%d]\n", minx, miny, resource);
    return (0);
}


