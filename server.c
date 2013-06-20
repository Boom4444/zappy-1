/*
** server.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Tue May 21 09:42:30 2013 Marin Alcaraz
** Last update Thu Jun 20 19:05:20 2013 ivan ignatiev
*/

#include    "server.h"
#include    "select.h"

int         server_handshake(int fd)
{
    server_welcome_msg(fd);
    return (1);
}

int            server_send(t_user *u, char *message)
{
    send(u->clientfd, message, strlen(message), MSG_DONTWAIT);
    return (1);
}

int                         server_start(t_server *s, t_world *w)
{
    struct  sockaddr_in     s_in;
    int                     result;
    clock_t                 start_loop;
    clock_t                 end_loop;

    s->client_list = list_init();
    s->server_fd = create_socket();
    init_sockadd(&s_in, s->options.port);
    if (bind(s->server_fd,
        (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
      error_log("server_start", "bind", strerror(errno));
    listen(s->server_fd, QUEUE_LIMIT);
    result = 0;
    s->tick = 0;
    s->diff = 0;
    while(result == 0)
    {
        start_loop = clock();
        result = select_do(s, w);
        end_loop = clock();
        if (s->diff)
        printf("loop [%llu] : %llu - %llu %f sec.\n", (unsigned long long)s->tick,
                (unsigned long long)(end_loop),
                (unsigned long long)(start_loop),
                (float)(end_loop - start_loop) / CLOCKS_PER_SEC );
        s->diff = 0;
        ++s->tick;
    }
    close(s->server_fd);
    return (0);
}
