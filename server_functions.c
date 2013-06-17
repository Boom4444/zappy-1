/*
** server_functions.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Mon May 27 13:47:20 2013 Marin Alcaraz
** Last update Mon Jun 10 12:44:22 2013 Marin Alcaraz
*/

#include "server_functions.h"

char     *server_getTNumber()
{
    return ("1");
}

char     *server_getXY()
{
    return ("8, 8");
}

int     server_welcome_msg(int fd)
{
    if (write(fd, "BIENVENUE\n", sizeof("BIENVENUE\n")) == -1)
    {
        error_show("server_welcome_msg", "write", strerror(errno));
        return (-1);
    }
    return (0);
}
