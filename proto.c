/*
** proto.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Jun 12 16:34:40 2013 Marin Alcaraz
** Last update Thu Jul 11 20:26:04 2013 ivan ignatiev
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
#include        "str.h"


int             proto_flud_detect(t_user *u, char *buf)
{
    if (strchr(buf, '\n') == NULL)
    {
        error_show("clu_parse", "", "Flud client detected");
        u->connected = DISCONNECTED;
        return (-1);
    }
    return (0);
}

int             cli_parse(t_user_player *u, t_server *s, t_world *w)
{
    t_request   *request;
    int         rb;
    char        buf[PROTO_BUFFER + 1];

    (void) w;
    if ((rb = recv(u->clientfd, buf, PROTO_BUFFER, MSG_DONTWAIT)) > 0)
    {
        buf[rb] = '\0';
        if (proto_flud_detect(T_USER(u), buf) < 0)
            return (-1);
        u->request_buf = stralloccat(u->request_buf, buf);
        while ((u->request = getnextline(u->request_buf)) != NULL)
        {
            if (u->request_counter > REQUESTS_LIMIT)
            {
                free(u->request);
                cli_answer(u, s, "ko\n");
                error_show("cli_parse", "", "Player %d request limit", u->number);
            }
            if ((request = cli_request_parse(s, u)) != NULL)
            {
                request->data->user->request_counter++;
                item_pb(s->request_list, (void*)request, sizeof(t_request));
            }
            else
            {
                free(request);
                cli_answer(u, s, "ko\n");
                error_show("cli_parse", "", "Player %d wrong request", u->number);
            }
        }
        return (0);
    }
    u->connected = DISCONNECTED;
    return (-1);
}

int        graph_parse(t_user_graph *u, t_server *s, t_world *w)
{
    int     rb;
    char    buf[PROTO_BUFFER + 1];

    if ((rb = recv(u->clientfd, buf, PROTO_BUFFER, MSG_DONTWAIT)) > 0)
    {
        buf[rb] = '\0';
        if (proto_flud_detect(T_USER(u), buf) < 0)
            return (-1);
        u->request_buf = stralloccat(u->request_buf, buf);
        while ((u->request = getnextline(u->request_buf)) != NULL)
        {
            log_show("graph_parse", "", "GFX Request '%s' accepted", u->request);
            graph_command_exec(u, s, w, u->request);
            free(u->request);
        }
        return (0);
    }
    u->connected = DISCONNECTED;
    return (-1);
}

int         proto_parse(t_user *u, t_server *s, t_world *w)
{
    if (u->protocol == CLI_PROTO)
        return (cli_parse((t_user_player*)u, s, w));
    return (graph_parse((t_user_graph*)u, s, w));
}

void            user_player_connected(t_user_player *u, t_server *s, t_world *w)
{
    char        answer[PROTO_BUFFER + 1];

    u->number = ++(s->players_count);
    log_show("user_player_init", "", "Player %d created in team '%s'", u->number, u->team->name);
    ++(u->team->members);
    --(u->team->limit);
    u->life = 0;
    sprintf(answer, "%d\n", u->team->limit);
    cli_answer(u, s, answer);
    sprintf(answer, "%d %d\n", w->width, w->height);
    cli_answer(u, s, answer);
    sprintf(answer, "pnw %d %d %d %d %d %s\n", u->number, u->posx, u->posy, u->orientation, u->level, u->team->name);
    cli_answer_to_all_graph(s, answer);
}

t_user              *proto_define(t_user *u, t_server *s, t_world *w)
{
    t_team          *team;
    t_user_player   *tmp;
    int             rb;
    char            buf[PROTO_BUFFER + 1];

    if ((rb = recv(u->clientfd, buf, PROTO_BUFFER, MSG_DONTWAIT)) > 0)
    {
        buf[rb] = '\0';
        if (proto_flud_detect(u, buf) < 0)
            return (NULL);
        u->request_buf = stralloccat(u->request_buf, buf);
        if ((u->request = getnextline(u->request_buf)) != NULL)
        {
            if (strcmp(u->request, "GRAPHIC") == 0)
            {
                u =  ((t_user*)user_graph_init(u));
                graph_client_init(T_GRAPH(u), s, w);
                free(u->request);
                return (u);
            }
            else if ((team = team_search(s->team_list, u->request)) != NULL
                    && team->limit > 0)
            {
                tmp = user_player_egg(u, team, w, s);
                u = T_USER(tmp == NULL ? user_player_init(u, team, w, s) : tmp);
                user_player_connected(T_PLAYER(u), s, w);
                free(u->request);
                return (u);
            }
        }
        error_show("proto_define", "", "Limit of players or undefined team");
        server_send(u->clientfd, "ko\n");
    }
    u->connected = DISCONNECTED;
    return (NULL);
}
