/*
** request.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Thu Jun 20 20:00:46 2013 ivan ignatiev
** Last update Thu Jul 04 21:38:51 2013 ivan ignatiev
*/

#include        "main.h"
#include        "list.h"
#include        "options.h"
#include        "trantor.h"
#include        "server.h"
#include        "users.h"
#include        "request.h"
#include        "proto.h"
#include        "cli_command_parse.h"
#include        "proto_commands_net.h"
#include        "proto_commands_movement.h"
#include        "proto_commands_items.h"


t_request_type  cli_commands[] =
{
    {"avance", 7, 0, cli_parse_avance, cli_avance },
    {"droite", 7, 0, cli_parse_droite, cli_droite },
    {"gauche", 7, 0, cli_parse_gauche, cli_gauche  },
    {"voir", 7, 0, cli_parse_voir, cli_voir },
    {"inventaire", 7, 0, cli_parse_inventaire, cli_inventaire },
    {"prend", 7, 1, cli_parse_prend, cli_prend },
    {"pose", 7, 1, cli_parse_pose, cli_pose },
    {"expluse", 7, 0, cli_parse_expulse, cli_expulse },
    {"broadcast", 7, 1, cli_parse_broadcast, cli_broadcast  },
    {"incantation", 300, 0, cli_parse_incantation, cli_incantation },
    {"fork", 42, 0, cli_parse_fork, cli_fork_player },
    {"connect_nbr", 0, 0, cli_parse_connect_nbr, cli_connect_nbr },
    {NULL, 0, 0, NULL, NULL }
};

t_request_data          *cli_request_data_init(char *message, int argc)
{
    t_request_data      *rqd;

    if((rqd = (t_request_data*)malloc(sizeof(t_request_data))) != NULL)
    {
        rqd->message = message;
        rqd->argv = NULL;
        if (argc > 0
            && (rqd->argv = (void**)malloc(sizeof(void*) * argc)) == NULL)
        {
            free(rqd);
            return (NULL);
        }
    }

    return (rqd);
}

t_request               *cli_request_init()
{
    t_request           *request;

    if ((request = (t_request*)malloc(sizeof(t_request))) != NULL)
    {
    }

    return (request);
}

t_request               *cli_request_parse(t_server *s, t_user_player *user)
{
    t_request           *request;
    int                 i;

    if ((request = cli_request_init()) != NULL)
    {
        i = 0;
        while (cli_commands[i].cmd)
        {
            if (strncmp(cli_commands[i].cmd, user->request, strlen(cli_commands[i].cmd)) == 0)
            {
                request->type = &cli_commands[i];
                request->tick = (user->tick > s->tick ? user->tick : s->tick) + request->type->delay;
                printf("Request will implemented %llu tick\n", request->tick);
                if (request->type->parse != NULL)
                {
                    if ((request->data = request->type->parse(request->type, user->request)) != NULL)
                    {
                        request->data->user = user;
                    }
                }
                else
                    request->data = NULL;
                user->tick = request->tick;
                return (request);
            }
            ++i;
        }
        free(request);
    }
    return (NULL);
}


void            cli_requests_process(t_server *s, t_world *w)
{
    t_item      *current;
    t_item      *tmp;

    current = s->request_list->head;
    while (current != NULL)
    {
        if (T_REQUEST(current)->type->func != NULL
                && T_REQUEST(current)->data != NULL
                && s->tick >= T_REQUEST(current)->tick)
        {
            printf("Request implemented %llu tick\n", s->tick);
            T_REQUEST(current)->type->func(T_REQUEST(current)->data, s, w);
            s->diff = 1;
            tmp = current;
            current = current->next;
            item_delete(s->request_list, tmp);
        }
        else
            current = current->next;
    }
}


