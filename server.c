/*
** server.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Tue May 21 09:42:30 2013 Marin Alcaraz
** Last update Wed Jun 12 15:45:20 2013 Marin Alcaraz
*/

#include    "server.h"
#include    "select.h"

int         server_handshake(int fd)
{
    server_welcome_msg(fd);
    return (1);
}

int                         server_start(t_server *s, t_world *w)
{
    struct  sockaddr_in     s_in;

    s->client_list = list_init();
    s->server_fd = create_socket();
    init_sockadd(&s_in, s->options.port);
    if (bind(s->server_fd,
        (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
        my_error("Error: unable to bind\n");
    listen(s->server_fd, QUEUE_LIMIT);
    while(select_do(s, w) == 0);
    return (0);
}
