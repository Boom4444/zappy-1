/*
** server.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Tue May 21 09:42:30 2013 Marin Alcaraz
** Last update Mon Jun 10 12:45:08 2013 Marin Alcaraz
*/

#include    "server.h"

int         server_handshake(int fd)
{
    /*int     rb;*/
    /*char    *coordinates;*/
    /*char    *team;*/
    /*char    buf[1024];*/

    /*coordinates = server_getXY();*/
    /*team =  server_getTNumber();*/
    server_welcome_msg(fd);
    /*rb = read(fd, buf, 1024);*/
    /*write(STDIN_FILENO, buf, rb);*/
    /*write(fd, team, strlen(team));*/
    /*write(fd, coordinates, strlen(team));*/
    return (1);
}

void        server_handleclient(struct sockaddr_in *s_client, int *fds)
{
    char    *client_ip;

    (void) *fds;
    client_ip = strdup(inet_ntoa(s_client->sin_addr));
    printf("Client ip: %s \n", client_ip);
    log_access(client_ip);
    /*if (server_handshake(fds, client_ip) == 1)*/
    /*{*/

    /*}*/
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
    while(SERVER_RUN)
        select_do(clients, fds[SERV_FD]);
}
