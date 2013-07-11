/*
** answer.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Thu Jun 20 20:02:59 2013 ivan ignatiev
** Last update Thu Jul 11 20:26:59 2013 ivan ignatiev
*/

#include        "main.h"
#include        "list.h"
#include        "options.h"
#include        "trantor.h"
#include        "server.h"
#include        "users.h"
#include        "answer.h"
#include        "error.h"

t_answer        *cli_answer_create(t_user_player *user, char *message)
{
    t_answer    *answer;

    if ((answer = (t_answer*)malloc(sizeof(t_answer))) != NULL)
    {
        if ((answer->message = strdup(message)) != NULL)
        {
            answer->user = user;
            return (answer);
        }
    }
    error_show("cli_answer_create", "malloc", "Unable allocate memory for answer");
    return (NULL);
}

void            cli_answer(t_user_player *user, t_server *server, char *message)
{
    t_answer    *answer;

    if ((answer = cli_answer_create(user, message)) != NULL)
    {
        item_pb(server->answer_list, answer, sizeof(t_answer));
    }
}

void            cli_answer_to_all_graph(t_server *server, char *message)
{
    t_item      *current;

    current = list_get_head(server->client_list);
    while (current != NULL)
    {
        if (T_USER(current->cont)->protocol == GRAPHIC_PROTO)
         {
             if (server_send(T_GRAPH(current->cont)->clientfd, message) <= 0)
                 T_ANSWER(current)->user->connected = DISCONNECTED;
         }
        current = current->next;
    }
}

void            cli_answer_to_graph(t_user_graph *u, char *message)
{
    if (server_send(u->clientfd, message) <= 0)
        u->connected = DISCONNECTED;
}

void                            cli_answers_process(t_server *s,
                                        struct timeval *start,
                                        unsigned long long tick_size)
{
    t_item                      *next;
    t_item                      *current;
    struct timeval              iter;
    unsigned long long          elapsedTime;

    current = list_get_head(s->answer_list);
    elapsedTime = 0;
    while (elapsedTime < tick_size && current != NULL)
    {
        next = current->next;
        if (server_send(T_ANSWER(current)->user->clientfd, T_ANSWER(current)->message) <= 0)
            T_ANSWER(current)->user->connected = DISCONNECTED;
        free(T_ANSWER(current)->message);
        free(current->cont);
        item_delete(s->answer_list, current);
        gettimeofday(&iter, NULL);
        elapsedTime = (iter.tv_sec - start->tv_sec) * 1000000;
        elapsedTime = elapsedTime + (iter.tv_usec - start->tv_usec);
        current = next;
    }
    if (elapsedTime < tick_size)
        usleep(tick_size - elapsedTime);
}


