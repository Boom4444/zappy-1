/*
** server_functions.c for server in /home/hero/zappy/server
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Mon May 27 13:47:20 2013 Marin Alcaraz
** Last update Wed Jun 05 12:48:47 2013 Marin Alcaraz
*/

#include "server_functions.h"

char     *server_getTNumber()
{
    return ("1");
}

char     *server_getXY()
{
    return ("8. 8");
}

int     server_welcome_msg(int fd)
{
    if (write(fd, "BIENVENUE\n", sizeof("BIENVENUE\n")) == -1)
    {
        my_error("Error: Unable to write welcome msg on client");
        log_error("Unable to write welcome msg on client FD ", fd);
        return (-1);
    }
    return (0);
}