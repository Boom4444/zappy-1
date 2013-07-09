/*
** cli_command_parse.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Thu Jun 13 17:27:55 2013 ivan ignatiev
** Last update Thu Jul 04 21:21:31 2013 ivan ignatiev
*/

#include        "main.h"
#include        "list.h"
#include        "options.h"
#include        "trantor.h"
#include        "server.h"
#include        "users.h"
#include        "proto.h"
#include        "request.h"
#include        "cli_command_parse.h"
#include        "answer.h"

t_request_data          *cli_parse_avance(t_request_type *type, t_user_player *u, t_server *s)
{
    t_request_data      *rqd;

    (void) s;
    if ((rqd = cli_request_data_init(u->request, type->argc)) != NULL)
    {

    }
    return (rqd);
}

t_request_data          *cli_parse_droite(t_request_type *type, t_user_player *u, t_server *s)
{
    t_request_data      *rqd;

    (void) s;
    if ((rqd = cli_request_data_init(u->request, type->argc)) != NULL)
    {

    }
    return (rqd);
}

t_request_data          *cli_parse_gauche(t_request_type *type, t_user_player *u, t_server *s)
{
    t_request_data      *rqd;

    (void) s;
    if ((rqd = cli_request_data_init(u->request, type->argc)) != NULL)
    {

    }
    return (rqd);
}

t_request_data          *cli_parse_voir(t_request_type *type, t_user_player *u, t_server *s)
{
    t_request_data      *rqd;

    (void) s;
    if ((rqd = cli_request_data_init(u->request, type->argc)) != NULL)
    {

    }
    return (rqd);
}

t_request_data          *cli_parse_inventaire(t_request_type *type, t_user_player *u, t_server *s)
{
    t_request_data      *rqd;

    (void) s;
    if ((rqd = cli_request_data_init(u->request, type->argc)) != NULL)
    {

    }
    return (rqd);
}

t_request_data          *cli_parse_prend(t_request_type *type, t_user_player *u, t_server *s)
{
    t_request_data      *rqd;
    char                *object;

    (void) s;
    if ((rqd = cli_request_data_init(u->request, type->argc)) != NULL)
    {
        if ((object = (char*)malloc(sizeof(char) * (strlen(u->request) - 5))) != NULL)
        {
            sscanf(u->request, "prend %s\n", object);
            rqd->argv[0] = (void*)object;

            printf("prend '%s'\n", (char*)rqd->argv[0]);
            return (rqd);
        }
        free(rqd);
        rqd = NULL;
    }
    return (rqd);
}

t_request_data          *cli_parse_pose(t_request_type *type, t_user_player *u, t_server *s)
{
    t_request_data      *rqd;
    char                *object;

    (void) s;
    if ((rqd = cli_request_data_init(u->request, type->argc)) != NULL)
    {
        if ((object = (char*)malloc(sizeof(char) * (strlen(u->request) - 4))) != NULL)
        {
            sscanf(u->request, "pose %s\n", object);
            rqd->argv[0] = (void*)object;

            printf("pose '%s'\n", (char*)rqd->argv[0]);
            return (rqd);
        }
        free(rqd);
        rqd = NULL;
    }
    return (rqd);
}

t_request_data          *cli_parse_expulse(t_request_type *type, t_user_player *u, t_server *s)
{
    t_request_data      *rqd;

    (void) s;
    if ((rqd = cli_request_data_init(u->request, type->argc)) != NULL)
    {

    }
    return (rqd);
}

t_request_data          *cli_parse_broadcast(t_request_type *type, t_user_player *u, t_server *s)
{
    t_request_data      *rqd;
    char                *text;

    (void) s;
    if ((rqd = cli_request_data_init(u->request, type->argc)) != NULL)
    {
        if ((text = (char*)malloc(sizeof(char) * (strlen(u->request) - 9))) != NULL)
        {
            sscanf(u->request, "broadcast %s\n", text);
            rqd->argv[0] = (void*)text;

            printf("broadcast '%s'\n", (char*)rqd->argv[0]);
            return (rqd);
        }
        free(rqd);
        rqd = NULL;
    }

    return (rqd);
}

t_request_data          *cli_parse_incantation(t_request_type *type, t_user_player *u, t_server *s)
{
    t_request_data      *rqd;

    (void) s;
    if ((rqd = cli_request_data_init(u->request, type->argc)) != NULL)
    {

    }

    return (rqd);
}

t_request_data          *cli_parse_fork(t_request_type *type, t_user_player *u, t_server *s)
{
    t_request_data      *rqd;
    char                response[ANSWER_SIZE];

    (void) s;
    if ((rqd = cli_request_data_init(u->request, type->argc)) != NULL)
    {
        sprintf(response, "pfk %d\n", u->number);
        cli_answer_to_all_graph(s, response);
    }
    return (rqd);
}

t_request_data          *cli_parse_connect_nbr(t_request_type *type, t_user_player *u, t_server *s)
{
    t_request_data      *rqd;

    (void) s;
    if ((rqd = cli_request_data_init(u->request, type->argc)) != NULL)
    {

    }
    return (rqd);
}
