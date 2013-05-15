/*
** main.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Apr 10 21:47:13 2013 Marin Alcaraz
** Last update Wed May 15 17:45:17 2013 Marin Alcaraz
*/
#include <stdio.h>
#include "error.h"
#include "server.h"

int main(int ac, char **av)
{
    if (ac != 2)
      my_error("Usage: ./server port\n");
    server(atoi(av[1]));
    return (0);
}
