/*
** request.h for zappy in /home/hero/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Thu Jun 13 18:43:36 2013 ivan ignatiev
** Last update Thu Jul 11 12:34:55 2013 Marin Alcaraz
*/

#ifndef REQUEST_H_
# define REQUEST_H_

# define MAX_COMMAND_LENGTH         32
# define REQUESTS_LIMIT             10
# define T_REQUEST(request)         ((t_request*)(request->cont))


typedef struct          s_request_data
{
    t_user_player       *user;
    char                *message;
    void                **argv;
}                       t_request_data;

typedef struct          s_request_type t_request_type;


typedef         t_request_data *(*t_proto_func_parse)(t_request_type *type, t_user_player *u, t_server *s, t_world *w);
typedef         void (*t_proto_func)(t_request_data *rqd, t_server *s, t_world *w);

typedef struct          s_request_type
{
    char                *cmd;
    unsigned int        delay;
    unsigned int        argc;

    t_proto_func_parse  parse;
    t_proto_func        func;
}                       t_request_type;

typedef struct          s_request
{
    t_request_type      *type;
    t_request_data      *data;
    unsigned long long  tick;
}                       t_request;

t_request_type          *cli_request_type_init(void);
t_request_data          *cli_request_data_init(char *message, unsigned int argc);
t_request               *cli_request_init(void);
t_request               *cli_request_parse(t_server *s, t_user_player *user, t_world *w);
void                    cli_requests_process(t_server *s, t_world *w);

#endif /* !REQUEST_H_ */
