/*
** server.c for server in /home/hero/zappy/server
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Tue May 21 09:42:30 2013 Marin Alcaraz
** Last update Sun May 26 20:08:55 2013 Marin Alcaraz
*/

#include    "server.h"

int         server_handle_client(int fd, char const *ip)
{
    write(fd, "BIENVENUE\n", sizeof("BIENVENUE\n"));
}

void        server_handshake(struct sockaddr_in *s_client, int c_fd)
{
    char    *client_ip;

    client_ip = strdup(inet_ntoa(s_client->sin_addr));
    printf("Client ip: %s \n", client_ip);
    while (SERVER_RUN)
        server_handle_client(c_fd, client_ip);
    my_errorandclose("Handshake Failure\n", &c_fd);
}

int                         server_start(int port)
{
    int                     fds[3];
    struct  sockaddr_in     s_in;
    struct  sockaddr_in     s_client;
    socklen_t               s_in_size;

    fds[LIMIT] = LIMIT;
    fds[SERV_FD] = create_socket();
    init_sockadd(&s_in, port);
    if (bind(fds[SERV_FD], (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
        my_error("Error: unable to bind\n");
    listen(fds[SERV_FD], QUEUE_LIMIT);
    while(SERVER_RUN)
    {
        fds[CLI_FD] = accept(fds[SERV_FD], (struct sockaddr *)&s_client, &s_in_size);
        if (fds[CLI_FD] == -1)
            my_errorandclose("Error acceptiong the request", fds);
        server_handshake(&s_client, fds[CLI_FD]);
    }


}
