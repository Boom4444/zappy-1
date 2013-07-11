/*
** server.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Tue May 21 09:42:30 2013 Marin Alcaraz
** Last update Thu Jul 11 17:44:17 2013 ivan ignatiev
*/

#include                "main.h"
#include                "list.h"
#include                "options.h"
#include                "connection_utils.h"
#include                "error.h"
#include                "trantor.h"
#include                "server.h"
#include                "users.h"
#include                "request.h"
#include                "answer.h"
#include                "select.h"

int                     server_handshake(int fd)
{
    if (server_send(fd, "BIENVENUE\n") == -1)
        return (error_show("server_welcome_msg", "write", strerror(errno)));
    return (0);
}

int                     server_send(int clientfd, char *message)
{
    char                test[1];

    if (recv(clientfd, test, 0, MSG_DONTWAIT) == -1
        && errno == 11)
        send(clientfd, message, strlen(message), MSG_DONTWAIT);
    return (1);
}

void                    server_init(t_server *s)
{
    log_show("server_start", "", "Server start");
    s->client_list = list_init();
    s->team_list = team_list_init(s, s->options.names);
    s->request_list = list_init();
    s->answer_list = list_init();
    s->server_fd = create_socket();
    s->tick = 0;
    s->diff = 0;
    s->players_count = 0;
    s->eggs_count = 0;
}

void                    server_stop(t_server *s)
{
    t_item              *current;

    current = s->client_list->head;
    while (current != NULL)
    {
        if (T_USER(current->cont)->clientfd >= 0)
            close(T_USER(current->cont)->clientfd);
        current = current->next;
    }
    close(s->server_fd);
    log_show("server_stop", "", "Server stop");
}

int                     server_start(t_server *s, t_world *w)
{
    struct sockaddr_in  s_in;
    struct timeval      start_loop;
    struct timeval      stop_loop;
    unsigned long long    elapsedTime;

    server_init(s);
    init_sockadd(&s_in, s->options.port);
    if (bind(s->server_fd, (const struct sockaddr *)&s_in,
                sizeof(s_in)) == -1)
    {
        close(s->server_fd);
        return (error_show("server_start", "bind", "Unable to bind the server socket"));
    }
    listen(s->server_fd, QUEUE_LIMIT);
    s->tick_size = 1000000 / s->options.tdelay;
    while(s->result == 0)
    {
        gettimeofday(&start_loop, NULL);
        select_do(s, w);
        cli_requests_process(s, w);
        users_life_proccess(s, w);
        cli_answers_process(s, w, &start_loop, s->tick_size);
        gettimeofday(&stop_loop, NULL);
        elapsedTime = (stop_loop.tv_sec - start_loop.tv_sec) * 1000000;
        elapsedTime = elapsedTime + (stop_loop.tv_usec - start_loop.tv_usec);
        if (s->diff)
            log_show("server_start", "", "Last command time : %lf sec. %llu tick", (double) elapsedTime / 1000000.0, s->tick);
        s->diff = 0;
        ++s->tick;
    }
    server_stop(s);
    return (0);
}
