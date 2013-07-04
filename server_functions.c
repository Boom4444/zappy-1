/*
** server_functions.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Mon May 27 13:47:20 2013 Marin Alcaraz
** Last update Thu Jul 04 21:16:07 2013 ivan ignatiev
*/

#include "main.h"
#include "list.h"
#include "options.h"
#include "trantor.h"
#include "server.h"
#include "connection_utils.h"
#include "error.h"
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
