/*
** main.c for server in /home/hero/zappy/server
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Apr 10 21:47:13 2013 Marin Alcaraz
** Last update Sun May 26 20:41:28 2013 Marin Alcaraz
*/
#include <stdio.h>
#include "error.h"
#include "server.h"
#include "log.h"

int main(int ac, char **av)
{
    if (ac != 2)
    {
      my_error("Usage: ./server port\n");
      log_error("Error: invalid usage [returned ", -1);
      return (-1);
    }
    server_start(atoi(av[1]));
    return (0);
}
