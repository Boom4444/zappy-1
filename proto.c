/*
** proto.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Jun 12 16:34:40 2013 Marin Alcaraz
** Last update Mon Jul 08 16:39:00 2013 ivan ignatiev
*/

#include        "main.h"
#include        "list.h"
#include        "options.h"
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

    if ((rb = recv(u->clientfd, buf, PROTO_BUFFER, MSG_DONTWAIT)) > 0)
    {
        buf[rb] = '\0';
        if (u->request == NULL && (u->request = (char*)malloc(sizeof(char) * ( strlen(buf) + 1))) != NULL)
            strcpy(u->request, buf);
        else if ((u->request = (char*)realloc(u->request, sizeof(char) * (strlen(buf) + strlen(u->request) + 1))) != NULL)
            strcat(u->request, buf);
        if (u->request != NULL && strchr(u->request, '\n') != NULL)
        {
            u->request[strlen(u->request) - 1] = '\0';
            if (u->request_counter > REQUESTS_LIMIT)
            {
                u->request = NULL;
                cli_answer(u, s, "ko\n");
                return (-1);
            }
            if ((request = cli_request_parse(s, u)) != NULL)
            {
                request->data->user->request_counter++;
                item_pb(s->request_list, (void*)request, sizeof(t_request));
            }
            else
                cli_answer(u, s, "ko\n");
            u->request = NULL;
        }
        return (0);
    }
    user_destroy(T_USER(u), s, w);
    return (-1);
}

int        graph_parse(t_user_graph *u, t_server *s, t_world *w)
{
    int     rb;
    char    buf[PROTO_BUFFER + 1];

    if ((rb = recv(u->clientfd, buf, PROTO_BUFFER, MSG_DONTWAIT)) > 0)
    {
        buf[rb - 1] = '\0';
        log_show("graph_parse", "", "Request '%s' accepted", buf);
        return (graph_command_exec(u, s, w, buf));
    }
    user_destroy(T_USER(u), s, w);
    return (-1);
}

int         proto_parse(t_user *u, t_server *s, t_world *w)
{
    if (u->protocol == CLI_PROTO)
    {
        // check request_counter here
        return (cli_parse((t_user_player*)u, s, w));
    }
    return (graph_parse((t_user_graph*)u, s, w));
}

t_user          *proto_define(t_user *u, t_server *s, t_world *w)
{
    t_team      *team;
    int         rb;
    char        buf[PROTO_BUFFER + 1];
    char        answer[PROTO_BUFFER + 1];

    (void) (w);
    if ((rb = read(u->clientfd, buf, 256)) > 0)
    {
        buf[rb - 1] = '\0';
        if (strcmp(buf, "GRAPHIC") == 0)
        {
            u =  ((t_user*)user_graph_init(u));
            // function which send all data
            return (u);
        }
        if (s->players_slots > 0 && (team = team_search(s->team_list, buf)) != NULL)
        {
            u = (t_user*)user_player_init(u, team, w, s);
            (team->members)++;
            (s->players_slots)--;
            sprintf(answer, "%d\n", s->players_slots);
            cli_answer((t_user_player*)u, s, strdup(answer));
            sprintf(answer, "%d %d\n", s->options.width, s->options.height);
            cli_answer((t_user_player*)u, s, strdup(answer));
            return (u);
        }
        error_show("proto_define", "", "Limit of players or undefined team");
        cli_answer((t_user_player*)u, s, "mort\n");
    }
   user_destroy(T_USER(u), s, w);
   return (NULL);
}
