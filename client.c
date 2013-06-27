/*
** client.c for zappy in /home/hero/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Fri May 24 19:45:50 2013 ivan ignatiev
** Last update Wed Jun 12 14:58:18 2013 Marin Alcaraz
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

int                 client_process(int sfd, fd_set *fdreadset)
{
    char            buf[255];
    int             len;

    if (FD_ISSET(1, fdreadset))
    {
        if ((len = read(1, buf, 255)) <= 0)
            return (-1);
        buf[len] = '\0';
        printf("#zappy(client)<--%s", buf);
        if (write(sfd, buf, len) < 0)
            return (-1);
    }

    if (FD_ISSET(sfd, fdreadset))
    {
        if ((len = read(sfd, buf, 255)) <= 0)
            return (-1);
        buf[len] = '\0';
        printf("zappy(server)-->%s", buf);
    }

    return (1);
}

int                 client_prompt(int sfd)
{
    int             prompt;
    int             rs;
    fd_set          fdreadset;
    char            delim;

    prompt = 1;
    delim = '#';
    while (prompt > 0)
    {
        FD_ZERO(&fdreadset);
        FD_SET(1, &fdreadset);
        FD_SET(sfd, &fdreadset);
        write(0, &delim, 1);
        if ((rs = select(sfd + 1, &fdreadset, NULL, NULL, NULL)) < 0)
            prompt = -1;
        else
            prompt = client_process(sfd, &fdreadset);
    }
    close(sfd);
    return (prompt == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
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
    {
        printf("%s: Too few arguments\n\t-h [host] %%s\n\t-p [port] %%s\n",
             argv[0]);
        return (EXIT_FAILURE);
    }
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
        return (error_show("main", "socket_connect", "Connection failed"));
    return (client_prompt(sfd));
}
