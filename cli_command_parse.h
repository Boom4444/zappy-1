/*
** cli_command_parse.h for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Thu Jun 13 19:09:46 2013 ivan ignatiev
** Last update Thu Jun 20 18:36:30 2013 ivan ignatiev
*/

#ifndef CLI_COMMAND_PARSE_H_
# define CLI_COMMAND_PARSE_H_

t_request_data          *request_data_init(char *message, int argc);
t_request               *request_init();
t_request               *cli_parse_request(t_user *user);
t_request_data          *cli_parse_avance(t_request_type *type, char *message);
t_request_data          *cli_parse_droite(t_request_type *type, char *message);
t_request_data          *cli_parse_gauche(t_request_type *type, char *message);
t_request_data          *cli_parse_voir(t_request_type *type, char *message);
t_request_data          *cli_parse_inventaire(t_request_type *type, char *message);
t_request_data          *cli_parse_prend(t_request_type *type, char *message);
t_request_data          *cli_parse_pose(t_request_type *type, char *message);
t_request_data          *cli_parse_expulse(t_request_type *type, char *message);
t_request_data          *cli_parse_broadcast(t_request_type *type, char *message);
t_request_data          *cli_parse_incantation(t_request_type *type, char *message);
t_request_data          *cli_parse_fork(t_request_type *type, char *message);
t_request_data          *cli_parse_connect_nbr(t_request_type *type, char *message);

#endif /* !CLI_COMMAND_PARSE_H_ */