/*
** connection_utils.h for zappy in /home/ignatiev/Projects/zappy
** 
* Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Thu Apr 11 19:11:16 2013 Marin Alcaraz
** Last update Sat Jul 13 18:57:12 2013 ivan ignatiev
*/

#ifndef CONNECTION_UTILS_H_
# define CONNECTION_UTILS_H_

# define SERVER		1
# define CLIENT		2
# define MAX_PEERS	3

void	init_sockadd(struct sockaddr_in *, int);
int	create_socket(void);

#endif /* !CONNECTION_UTILS_H_ */
