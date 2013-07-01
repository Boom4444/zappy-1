/*
** answer.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Thu Jun 20 20:02:59 2013 ivan ignatiev
** Last update Wed Jun 26 16:11:29 2013 ivan ignatiev
*/

#include                <sys/time.h>
#include                <time.h>
#include        "users.h"
#include        "server.h"
#include        "answer.h"

t_answer        *cli_answer_create(t_user *user, char *message)
{
    t_answer    *answer;

    if ((answer = (t_answer*)malloc(sizeof(t_answer))) != NULL)
    {
        answer->message = message;
        answer->user = user;
    }

    return (answer);
}

void            cli_answer(t_user *user, t_server *server, char *message)
{
    t_answer    *answer;

    if ((answer = cli_answer_create(user, message)) != NULL)
    {
        item_pb(server->answer_list, answer, sizeof(t_answer));
    }
}

void            cli_answer_to_graph(t_server *server, char *message)
{
    t_item      *current;

    current = server->client_list->head;
    while (current != NULL)
    {
        if (T_USER(current)->protocol == GRAPHIC_PROTO
             && T_USER(current)->connected)
         {
             server_send(T_USER(current), message);
         }
        current = current->next;
    }
}

void                            cli_answers_process(t_server *s, 
                                        struct timeval *start, 
                                        unsigned long long tick_size)
{
    t_item                      *tmp;
    t_item                      *current;
    struct timeval              iter;
    unsigned long long          elapsedTime;

    current = s->answer_list->head;
    elapsedTime = 0;
    while (elapsedTime < tick_size && current != NULL)
    {
        server_send(T_ANSWER(current)->user, T_ANSWER(current)->message);
        tmp = current;
        current = current->next;
        item_delete(s->answer_list, tmp);
        gettimeofday(&iter, NULL);
        elapsedTime = (iter.tv_sec - start->tv_sec) * 1000000;
        elapsedTime = elapsedTime + (iter.tv_usec - start->tv_usec);
    }
    
    if (elapsedTime < tick_size)
        usleep(tick_size - elapsedTime);
}


