/*
** server.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Tue May 21 09:42:30 2013 Marin Alcaraz
** Last update Wed Jul 03 10:48:06 2013 Marin Alcaraz
*/

#include                <sys/time.h>
#include                "server.h"
#include                "users.h"
#include                "request.h"
#include                "answer.h"
#include                "select.h"

int                     server_handshake(int fd)
{
    server_welcome_msg(fd);
    return (1);
}

int                     server_send(t_user *u, char *message)
{
    send(u->clientfd, message, strlen(message), MSG_DONTWAIT);
    return (1);
}

void                    server_init(t_server *s)
{
    s->client_list = list_init();
    s->request_list = list_init();
    s->answer_list = list_init();
    s->server_fd = create_socket();
    s->tick = 0;
    s->diff = 0;
}

int                     server_start(t_server *s, t_world *w)
{
    struct sockaddr_in  s_in;
    int                 result;
    struct timeval      start_loop;
    struct timeval      stop_loop;
    unsigned long long    elapsedTime;

    server_init(s);
    init_sockadd(&s_in, s->options.port);
    if (bind(s->server_fd,
                (const struct sockaddr *)&s_in,
                sizeof(s_in)) == -1)
    {
        if (error_show("server_start", "bind", strerror(errno)) == 1)
        {
            close(s->options.port);
            return (EXIT_FAILURE);
        }
    }
    listen(s->server_fd, QUEUE_LIMIT);
    result = 0;
    while(result == 0)
    {
        gettimeofday(&start_loop, NULL);
        result = select_do(s, w);
        cli_requests_process(s, w);
        cli_answers_process(s, &start_loop, 5000);
        gettimeofday(&stop_loop, NULL);
        elapsedTime = (stop_loop.tv_sec - start_loop.tv_sec) * 1000000;
        elapsedTime = elapsedTime + (stop_loop.tv_usec - start_loop.tv_usec);
        if (s->diff)
                printf("%lf sec.\n", (double) elapsedTime / 1000000.0);
        s->diff = 0;
        ++s->tick;
    }
    close(s->server_fd);
    return (0);
}
