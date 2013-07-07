/*
** proto.c for zappy in /home/ignati_i/zappy/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Jun 12 16:34:40 2013 Marin Alcaraz
** Last update Sun Jul 07 17:20:42 2013 ivan ignatiev
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
    printf("Client disconnected\n");
    return (-1);
}

int        graph_parse(t_user_graph *u, t_server *s, t_world *w)
{
    int     rb;
    char    buf[PROTO_BUFFER + 1];

    if ((rb = recv(u->clientfd, buf, PROTO_BUFFER, MSG_DONTWAIT)) > 0)
    {
        buf[rb] = '\0';
        printf("Recv: %s\n", buf);
        return (graph_command_exec(u, s, w, buf));
    }
    close(u->clientfd);
    item_delete_by_content(s->client_list, (void*)u);
    printf("Client disconnected\n");
    return (-1);
}

int         proto_parse(t_user *u, t_server *s, t_world *w)
{
    if (u->protocol == CLI_PROTO)
        return (cli_parse((t_user_player*)u, s, w));
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
        printf("Recv: %s\n", buf);
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
            (s->options.cmax)--;
            sprintf(answer, "%d\n", s->players_slots);
            cli_answer((t_user_player*)u, s, answer);
            sprintf(answer, "%d %d\n", s->options.width, s->options.height);
            cli_answer((t_user_player*)u, s, answer);
            return (u);
        }
        cli_answer((t_user_player*)u, s, "mort\n");
    }
    close(u->clientfd);
    item_delete_by_content(s->client_list, (void*)u);
    return (NULL);
}
