/*
** proto.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Jun 12 16:34:40 2013 Marin Alcaraz
** Last update Tue Jul 09 19:46:51 2013 ivan ignatiev
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
                error_show("cli_parse", "", "Player %d request limit", u->number);
                cli_answer(u, s, "ko\n");
                return (-1);
            }
            if ((request = cli_request_parse(s, u)) != NULL)
            {
                request->data->user->request_counter++;
                item_pb(s->request_list, (void*)request, sizeof(t_request));
            }
            else
            {
                error_show("cli_parse", "", "Player %d wrong request", u->number);
                cli_answer(u, s, "ko\n");
            }
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
        log_show("graph_parse", "", "GFX Request '%s' accepted", buf);
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

void            user_player_connected(t_user_player *u, t_server *s, t_world *w)
{
    char        answer[PROTO_BUFFER + 1];

    u->number = ++(s->players_count);
    log_show("user_player_init", "", "Player %d created in team '%s'", u->number, u->team->name);
    ++(u->team->members);
    --(u->team->limit);
    sprintf(answer, "%d\n", u->team->limit);
    cli_answer(u, s, answer);
    sprintf(answer, "%d %d\n", w->width, w->height);
    cli_answer(u, s, answer);
    sprintf(answer, "pnw %d %d %d %d %d %s\n", u->number, u->posx, u->posy, u->orientation, u->level, u->team->name);
    cli_answer_to_all_graph(s, answer);
}

t_user          *proto_define(t_user *u, t_server *s, t_world *w)
{
    t_team      *team;
    int         rb;
    char        buf[PROTO_BUFFER + 1];

    if ((rb = recv(u->clientfd, buf, PROTO_BUFFER, MSG_DONTWAIT)) > 0)
    {
        buf[rb - 1] = '\0';
        if (strcmp(buf, "GRAPHIC") == 0)
        {
            u =  ((t_user*)user_graph_init(u));
            graph_client_init(T_GRAPH(u), s, w);
            return (u);
        }
        if ((team = team_search(s->team_list, buf)) != NULL && team->limit > 0)
        {
            u = (t_user*)user_player_init(u, team, w, s);
            user_player_connected(T_PLAYER(u), s, w);
            return (u);
        }
        error_show("proto_define", "", "Limit of players or undefined team");
        cli_answer((t_user_player*)u, s, "mort\n");
    }
    user_destroy(T_USER(u), s, w);
    return (NULL);
}
