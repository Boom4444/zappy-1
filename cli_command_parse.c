/*
** cli_command_parse.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Thu Jun 13 17:27:55 2013 ivan ignatiev
** Last update Tue Jun 25 17:35:56 2013 ivan ignatiev
*/

#include        <stdlib.h>
#include        "server.h"
#include        "users.h"
#include        "proto.h"
#include        "request.h"
#include        "cli_command_parse.h"

t_request_data          *cli_parse_avance(t_request_type *type, char *message)
{
    t_request_data      *rqd;

    if ((rqd = cli_request_data_init(message, type->argc)) != NULL)
    {

    }

    return (rqd);
}

t_request_data          *cli_parse_droite(t_request_type *type, char *message)
{
    t_request_data      *rqd;

    if ((rqd = cli_request_data_init(message, type->argc)) != NULL)
    {

    }

    return (rqd);
}

t_request_data          *cli_parse_gauche(t_request_type *type, char *message)
{
    t_request_data      *rqd;

    if ((rqd = cli_request_data_init(message, type->argc)) != NULL)
    {

    }

    return (rqd);
}

t_request_data          *cli_parse_voir(t_request_type *type, char *message)
{
    t_request_data      *rqd;

    if ((rqd = cli_request_data_init(message, type->argc)) != NULL)
    {

    }

    return (rqd);
}

t_request_data          *cli_parse_inventaire(t_request_type *type, char *message)
{
    t_request_data      *rqd;

    if ((rqd = cli_request_data_init(message, type->argc)) != NULL)
    {

    }

    return (rqd);
}

t_request_data          *cli_parse_prend(t_request_type *type, char *message)
{
    t_request_data      *rqd;
    char                *object;

    if ((rqd = cli_request_data_init(message, type->argc)) != NULL)
    {
        if ((object = (char*)malloc(sizeof(char) * (strlen(message) - 5))) != NULL)
        {
            sscanf(message, "prend %s\n", object);
            rqd->argv[0] = (void*)object;

            printf("prend '%s'\n", (char*)rqd->argv[0]);
            return (rqd);
        }
        free(rqd);
        rqd = NULL;
    }

    return (rqd);
}

t_request_data          *cli_parse_pose(t_request_type *type, char *message)
{
    t_request_data      *rqd;
    char                *object;

    if ((rqd = cli_request_data_init(message, type->argc)) != NULL)
    {
        if ((object = (char*)malloc(sizeof(char) * (strlen(message) - 4))) != NULL)
        {
            sscanf(message, "pose %s\n", object);
            rqd->argv[0] = (void*)object;

            printf("pose '%s'\n", (char*)rqd->argv[0]);
            return (rqd);
        }
        free(rqd);
        rqd = NULL;
    }
    return (rqd);
}

t_request_data          *cli_parse_expulse(t_request_type *type, char *message)
{
    t_request_data      *rqd;

    if ((rqd = cli_request_data_init(message, type->argc)) != NULL)
    {

    }

    return (rqd);
}

t_request_data          *cli_parse_broadcast(t_request_type *type, char *message)
{
    t_request_data      *rqd;
    char                *text;

    if ((rqd = cli_request_data_init(message, type->argc)) != NULL)
    {
        if ((text = (char*)malloc(sizeof(char) * (strlen(message) - 9))) != NULL)
        {
            sscanf(message, "broadcast %s\n", text);
            rqd->argv[0] = (void*)text;

            printf("broadcast '%s'\n", (char*)rqd->argv[0]);
            return (rqd);
        }
        free(rqd);
        rqd = NULL;
    }

    return (rqd);
}

t_request_data          *cli_parse_incantation(t_request_type *type, char *message)
{
    t_request_data      *rqd;

    if ((rqd = cli_request_data_init(message, type->argc)) != NULL)
    {

    }

    return (rqd);
}

t_request_data          *cli_parse_fork(t_request_type *type, char *message)
{
    t_request_data      *rqd;

    if ((rqd = cli_request_data_init(message, type->argc)) != NULL)
    {

    }

    return (rqd);
}

t_request_data          *cli_parse_connect_nbr(t_request_type *type, char *message)
{
    t_request_data      *rqd;

    if ((rqd = cli_request_data_init(message, type->argc)) != NULL)
    {

    }

    return (rqd);
}
