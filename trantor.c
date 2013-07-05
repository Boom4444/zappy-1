/*
** trantor.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 20 17:33:58 2013 Marin Alcaraz
** Last update Fri Jul 05 11:18:09 2013 Marin Alcaraz
*/

#include    "main.h"
#include    "list.h"
#include    "error.h"
#include    "trantor.h"
#define     RESOURCE_LIMIT  10

static      char g_resource[7][21]=
{
    {"Food"},
    {"Linemate"},
    {"Deraumere"},
    {"Sibur"},
    {"Mendiane"},
    {"Phiras"},
    {"Thystame"}
};

int        init_world(t_world *w, int width, int height)
{
    int      i;
    int      j;

    i = 0;
    j = 0;
    w->surface = (t_square_unit **) malloc(sizeof(t_square_unit *) * height);
    while (i < height)
    {
        if ((w->surface[i] = malloc(sizeof(t_square_unit) * width)) == NULL)
        {
            error_show("init_world", "init_world", "Error: can't allocate (width) game board\n");
            return (EXIT_FAILURE);
        }
        while (j < width)
        {
            w->surface[i][j].players = list_init();
            j = j + 1;
        }
        j = 0;
        i = i + 1;
    }
    w->width = width;
    w->height = height;
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
    printf("\n\n");
    while (i < height)
    {
        while (j < width)
        {
            if (mineral_checker(w->surface[i][j]) != 0)
                printf(" R ");
            else if ((w->surface[i][j]).players->head != NULL)
                printf(" P ");
            else
                printf(" * ");
            j = j + 1;
        }
        printf("\n");
        i = i + 1;
        j = 0;
    }
    printf("\n\n");
    return (0);
}

void        random_number(int *container, int limit)
{
    srand(time(NULL));
    *container = rand() % limit;
}


int         generate_resource(t_world *w, int width, int height)
{
    int     amount;
    int     minx;
    int     miny;
    int     resource;

    amount = 0;
    while (amount < RESOURCE_LIMIT)
    {
        random_number(&minx, width);
        random_number(&miny, height);
        random_number(&resource, 7);
        printf("Generated %s on %d, %d\n",g_resource[resource], minx, miny);
        (w->surface[miny][minx]).resources[resource]++;
        amount = amount + 1;
        usleep(888888);
    }
    return (0);
}


