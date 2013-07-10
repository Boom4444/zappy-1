/*
** proto_commands_net.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Jun 13 16:31:20 2013 Marin Alcaraz
** Last update Wed Jul 10 13:43:28 2013 Marin Alcaraz
*/

#include        "main.h"
#include        "list.h"
#include        "options.h"
#include        "trantor.h"
#include        "server.h"
#include        "users.h"
#include        "request.h"
#include        "answer.h"
#include        "proto_commands_net.h"
#include        "proto_commands_movement.h"
#include        "item.h"
#include        "incantation.h"
#include        "error.h"

static t_point  g_steps[] =
{
	{0, -1},
	{1, 0},
	{0, 1},
	{-1, 0}
};

static t_request_type   g_hatch_type = {"egg_hatch", 600, 0, NULL, cli_hatch_egg };

void        cli_expulse(t_request_data *rqd, t_server *s, t_world *w)
{
    int     new_position_x;
    int     new_position_y;
    int     current_dir;
    char    response[ANSWER_SIZE];

    current_dir = rqd->user->orientation;
    sprintf(response, "pex %d\n", rqd->user->number);
    cli_answer_to_all_graph(s, response);
    response[0] = '\0';
    new_position_x = _MOD(rqd->user->posx + g_steps[current_dir].x, w->width);
    new_position_y = _MOD(rqd->user->posy + g_steps[current_dir].y, w->height);
    expulse_square(new_position_x, new_position_y, rqd, w, s);
    cli_answer(rqd->user,s , "ok\n");
}

void                    cli_incantation(t_request_data *rqd, t_server *s, t_world *w)
{
    (void) rqd;
    (void) s;
    (void) w;
    /*init_incantation(rqd, s, w);*/
    /*if ((st = incantate(T_PLAYER(rqd->user), s, w)) != 0)*/
    /*{*/
        /*error_show("incantation", "cli",*/
                /*"Incantation failed!");*/
        /*cli_answer(rqd->user,s , "ko\n");*/
    /*}*/
    /*end_incantation(rqd, s, w);*/
    return ;
}

void                    cli_hatch_egg(t_request_data *rqd,
                                        t_server *s, t_world *w)
{
    char                response[ANSWER_SIZE];

    (void) w;
    ++(T_EGG(rqd->user)->team->limit);
    T_EGG(rqd->user)->hatched = 1;
    sprintf(response, "eht %d\n", T_EGG(rqd->user)->number);
    cli_answer_to_all_graph(s, response);
}

void                    cli_fork_player(t_request_data *rqd,
                                        t_server *s, t_world *w)
{
    t_user_egg         *user;
    t_request          *egg_request;
    char               response[ANSWER_SIZE];

    (void) w;
    if ((user = user_egg_init(rqd->user, s)) != NULL)
    {
        if ((egg_request = cli_request_init()) != NULL )
        {
            if ((egg_request->data = cli_request_data_init(strdup("egg_hatch"), 0)) != NULL)
            {
                user->number = (s->eggs_count)++;
                egg_request->data->user = T_PLAYER(user);
                egg_request->type = &g_hatch_type;
                egg_request->tick = s->tick + g_hatch_type.delay;
                item_pf(s->request_list, (void*)egg_request, sizeof(t_request));
                item_pf(s->client_list, (void*)user, sizeof(t_user_egg));
                sprintf(response, "enw %d %d %d %d\n", user->number,
                        user->parent_number, user->posx, user->posy);
                cli_answer_to_all_graph(s, response);
                cli_answer(rqd->user, s, "ok\n");
                return ;
            }
            free(egg_request);
        }
        free(user);
    }
    cli_answer(rqd->user, s, "ko\n");
}

void        cli_connect_nbr(t_request_data *rqd, t_server *s, t_world *w)
{
    char    answer[ANSWER_SIZE];

    (void) (w);
    sprintf(answer, "%u\n", rqd->user->team->limit);
    cli_answer(rqd->user, s, answer);
}

void    cli_death(t_request_data *rqd, t_server *t, t_world *w)
{
    (void) (w);
    (void) (t);
    (void) (rqd);
    printf("death\n");
}
