/*
** answer.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Thu Jun 20 20:02:59 2013 ivan ignatiev
** Last update Tue Jun 25 18:09:33 2013 ivan ignatiev
*/

#include    "users.h"
#include    "server.h"
#include    "answer.h"

t_answer    *cli_answer_create(t_user *user, char *message)
{
    t_answer    *answer;

    (void) user;
    (void) message;
    if ((answer = (t_answer*)malloc(sizeof(t_answer))) != NULL)
    {

    }

    return (answer);
}

void            cli_answer(t_user *user, t_server *server, char *message)
{
/*    t_answer    *answer;

    (void) server;
    if ((answer = cli_answer_create(user, message)) != NULL)
    {
        item_pb(server->answer_list, answer, sizeof(t_answer));
        server_send(user, message);
    }*/
    (void) server;
    server_send(user, message);
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

void        cli_answers_process(t_server *s)
{
    t_item  *current;

    current = s->answer_list->head;
    while (current != NULL)
    {
        server_send(T_ANSWER(current)->user, T_ANSWER(current)->message);
        current = current->next;
    }
}


