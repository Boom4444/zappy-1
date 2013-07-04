/*
** proto.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Jun 12 16:34:40 2013 Marin Alcaraz
** Last update Thu Jul 04 21:43:11 2013 ivan ignatiev
*/

#include        "main.h"
#include        "list.h"
#include        "options.h"
#include        "item.h"
#include        "trantor.h"
#include        "server.h"
#include        "users.h"
#include        "select.h"
#include        "request.h"
#include        "answer.h"
#include        "cli_command_parse.h"
#include        "graph_command.h"
#include        "proto.h"
#include        "error.h"

int            cli_parse(t_user_player *u, t_server *s, t_world *w)
{
    t_request   *request;
    int         rb;
    char        buf[PROTO_BUFFER + 1];

    (void) w;
    if ((rb = recv(u->clientfd, buf, PROTO_BUFFER, MSG_DONTWAIT)) > 0)
    {
        buf[rb] = '\0';
        if (u->request == NULL && (u->request = (char*)malloc(sizeof(char) * strlen(buf))) != NULL)
            strcpy(u->request, buf);
        else if ((u->request = (char*)realloc(u->request, sizeof(char) * (strlen(buf) + strlen(u->request) + 1))) != NULL)
            strcat(u->request, buf);
        if (u->request != NULL && strchr(u->request, '\n') != NULL)
        {
            if (u->request_counter > REQUESTS_LIMIT)
            {
                u->request = NULL;
                return (-1);
            }
            if ((request = cli_request_parse(s, u)) != NULL)
            {
                printf("request accepted %llu tick\n", s->tick);
                request->data->user->request_counter++;
                item_pb(s->request_list, (void*)request, sizeof(t_request));
            }
            u->request = NULL;
        }
        return (0);
    }
    close(u->clientfd);
    item_delete_by_content(s->client_list, (void*)u);
    return (-1);
}

int        graph_parse(t_user_graph *u, t_server *s, t_world *w)
{
    int     rb;
    char    buf[PROTO_BUFFER + 1];

    if ((rb = recv(u->clientfd, buf, PROTO_BUFFER, MSG_DONTWAIT)) > 0)
    {
        buf[rb] = '\0';
        return (graph_command_exec(u, s, w, buf));
    }
    close(u->clientfd);
    item_delete_by_content(s->client_list, (void*)u);
    return (-1);
}

int         proto_parse(t_user *u, t_server *s, t_world *w)
{
    if (u->protocol == CLI_PROTO)
        return (cli_parse((t_user_player*)u, s, w));
    return (graph_parse((t_user_graph*)u, s, w));
}

t_user         *proto_define(t_user *u, t_server *s, t_world *w)
{
    int     rb;
    char    buf[256];

    (void) (w);
    if ((rb = read(u->clientfd, buf, 256)) > 0)
    {
        buf[rb] = '\0';
        if (strcmp(buf, "GRAPHIC\n") == 0)
            return ((t_user*)user_graph_init(u));
        u = (t_user*)user_player_init(u, s);
        if (team_add_player(s->team_list, (t_user_player*)u, buf) == 0)
        {
            cli_answer((t_user_player*)u, s, "X Y\n");
            return (u);
        }
        cli_answer((t_user_player*)u, s, "mort\n");
    }
    close(u->clientfd);
    item_delete_by_content(s->client_list, (void*)u);
    return (NULL);
}
