/*
** server.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Tue May 21 09:42:30 2013 Marin Alcaraz
** Last update Mon Jul 08 13:38:50 2013 ivan ignatiev
*/

#include                "main.h"
#include                "list.h"
#include                "options.h"
#include                "connection_utils.h"
#include                "server_functions.h"
#include                "error.h"
#include                "trantor.h"
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

int                     server_send(int clientfd, char *message)
{
    send(clientfd, message, strlen(message), MSG_DONTWAIT);
    return (1);
}

void                    server_init(t_server *s)
{
    s->client_list = list_init();
    s->team_list = team_list_init(s->team_list, s->options.names);
    s->request_list = list_init();
    s->answer_list = list_init();
    s->server_fd = create_socket();
    s->players_slots = s->options.cmax;
    s->tick = 0;
    s->diff = 0;
    s->players_count = 0;
}

void                    server_stop(t_server *s)
{
    t_item              *current;

    printf("Server stop;\n");
    current = s->client_list->head;
    while (current != NULL)
    {
        close(T_USER(current->cont)->clientfd);
        current = current->next;
    }
    close(s->server_fd);
}

int                     server_start(t_server *s, t_world *w)
{
    struct sockaddr_in  s_in;
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
    s->tick_size = 1000000 / s->options.tdelay;
    while(s->result == 0)
    {
        gettimeofday(&start_loop, NULL);
        select_do(s, w);
        cli_requests_process(s, w);
        cli_answers_process(s, &start_loop, s->tick_size);
        gettimeofday(&stop_loop, NULL);
        elapsedTime = (stop_loop.tv_sec - start_loop.tv_sec) * 1000000;
        elapsedTime = elapsedTime + (stop_loop.tv_usec - start_loop.tv_usec);
        if (s->diff)
            printf("%lf sec. %llu tick.\n", (double) elapsedTime / 1000000.0, s->tick);
        s->diff = 0;
        ++s->tick;
    }
    server_stop(s);
    return (0);
}
