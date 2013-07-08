/*
** graph_command.h for zappy in /home/hero/zappy
** 
** Made by Ivan Ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Jun 12 17:02:27 2013 Marin Alcaraz
** Last update Mon Jul 08 13:32:36 2013 Marin Alcaraz
*/

#ifndef GRAPH_COMMAND_H
# define	GRAPH_COMMAND_H

# define    STR_LIMIT 512

typedef struct      s_graph_data
{
    char            *message;
    t_user_graph    *user;
}                   t_graph_data;

typedef         int (*t_graph_func)(t_graph_data *, t_server *, t_world *);

typedef struct  s_graph_command
{
    char        *cmd;
    t_graph_func func;
}               t_graph_command;

int             graph_command_exec(t_user_graph *u, t_server *s, t_world *w,
                                        char *message);
int             graph_command_msz(t_graph_data *, t_server *, t_world *);
int             graph_command_bct(t_graph_data *, t_server *, t_world *);
int             graph_command_mct(t_graph_data *, t_server *, t_world *);
int             graph_command_tna(t_graph_data *, t_server *, t_world *);
int             graph_command_ppo(t_graph_data *, t_server *, t_world *);
int             graph_command_piv(t_graph_data *, t_server *, t_world *);
int             graph_command_pin(t_graph_data *, t_server *, t_world *);
int             graph_command_sgt(t_graph_data *, t_server *, t_world *);
int             graph_command_sst(t_graph_data *, t_server *, t_world *);
int 		graph_display_users(t_server *s, t_graph_data *);
int 		graph_client_init(t_user_graph *, t_server *s, t_world *w);
int             graph_command_display(t_graph_data *, t_server *, t_world *);

#endif	/* GRAPH_COMMAND_H */
