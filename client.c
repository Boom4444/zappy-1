/*
** client.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Fri May 24 19:45:50 2013 ivan ignatiev
** Last update Wed May 29 21:54:13 2013 ivan ignatiev
*/

#include    <stdlib.h>
#include    <stdio.h>
#include    <sys/time.h>
#include    <sys/types.h>
#include    <signal.h>
#include    <unistd.h>

#include    "client.h"
#include    "socket.h"
#include    "error.h"

int                 client_prompt(int sfd)
{
    char            buf[255];
    int             len;
    int             prompt;
    int             rs;
    fd_set          fdreadset;
    char            delim;

    prompt = 1;
    delim = '#';

    while (prompt)
    {
        FD_ZERO(&fdreadset);
        FD_SET(1, &fdreadset);
        FD_SET(sfd, &fdreadset);
        write(0, &delim, 1);
        rs = select(sfd + 1, &fdreadset, NULL, NULL, NULL);
        if (rs == -1 && errno == EINTR)
        {
            printf("\n Close connection ... \n");
            prompt = 0;
        }
        else if (rs >= 0)
        {
            if (FD_ISSET(1, &fdreadset))
            {
                len = read(1, buf, 255);
                buf[len] = '\0';
                printf("#zappy(client)<--%s", buf);
                write(sfd, buf, len);
            }

            if (FD_ISSET(sfd, &fdreadset))
            {
                len = read(sfd, buf, 255);
                buf[len] = '\0';
                printf("zappy(server)-->%s", buf);
            }
        }
    }
    close(sfd);
    return (EXIT_SUCCESS);
}

int                 client_options(int argc, char **argv, t_options *options)
{
    options->host = NULL;
    options->port = NULL;
    while (-1 != (options->current = getopt(argc, argv, "h:" "p:" )))
    {
        if (options->current == 'h')
            options->host = optarg;
        else if (options->current == 'p')
            options->port = optarg;
    }
    if (!options->host || !options->port)
        return (error_show("Too few arguments\n\t-h [host]\n\t-p [port]\n"));
    return (EXIT_SUCCESS);
}

void                sigint_handler(int sig)
{
    (void) sig;
}

int                 main(int argc, char **argv)
{
    int             sfd;
    t_options       options;

    signal(SIGINT, sigint_handler);
    printf("Welcome to ZAPPY Smart Prompt!\n");
    if (client_options(argc, argv, &options) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    printf("Trying to connect %s : %s\n", options.host, options.port);
    if ((sfd = socket_connect(options.host, options.port)) < 0)
        return (error_show("Connection failed"));
    return (client_prompt(sfd));
}
