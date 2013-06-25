/*
** request.h for zappy in /home/hero/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Thu Jun 13 18:43:36 2013 ivan ignatiev
** Last update Mon Jun 24 11:57:33 2013 Marin Alcaraz
*/

#ifndef REQUEST_H_
# define REQUEST_H_

# define MAX_COMMAND_LENGTH         32

#include "server.h"
#include "select.h"
#include "error.h"

typedef struct  s_request_data
{
    char        *message;
    void        **argv;
}               t_request_data;

typedef struct          s_request_type t_request_type;


typedef         t_request_data *(*t_proto_func_parse)(t_request_type *type, char *message);
typedef         void (*t_proto_func)(t_request_data *rqd, t_server *s, t_world *w);

typedef struct          s_request_type
{
    char                *cmd;
    int                 delay;
    int                 argc;

    t_proto_func_parse  parse;
    t_proto_func        func;
}                       t_request_type;

typedef struct  s_request
{
    t_request_type    *type;
    t_request_data  *data;
    int             current_time;
}               t_request;

#endif /* !REQUEST_H_ */
