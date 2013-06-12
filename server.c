/*
** server.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Tue May 21 09:42:30 2013 Marin Alcaraz
** Last update Wed Jun 12 14:46:16 2013 Marin Alcaraz
*/

#include    "server.h"

int         server_handshake(int fd)
{
    server_welcome_msg(fd);
    return (1);
}

int                         server_start(t_opt *opt)
{
    int                     fds[3];
    t_list                  *clients;
    struct  sockaddr_in     s_in;

    fds[LIMIT] = LIMIT;
    clients = list_init();
    fds[SERV_FD] = create_socket();
    init_sockadd(&s_in, opt->port);
    if (bind(fds[SERV_FD], (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
        my_error("Error: unable to bind\n");
    listen(fds[SERV_FD], QUEUE_LIMIT);
    while(select_do(clients, fds[SERV_FD]) == 0);
    return (0);
}
