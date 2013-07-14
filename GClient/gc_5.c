/*
** gc_5.c for Zappy in /home/el/GitHub/zappy/GClient
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Sun Jul  14 21:35:31 2013 oleg kuznietsov
** Last update Sun Jul 14 21:50:50 2013 ivan ignatiev
*/

#include	"graph_commands.h"
#include	"gclient_funcs.h"
#include	"gclient_ping.h"

int	gcmd_pnw(char *cmd, t_pm *pm)
{
  ping_save(pm);
  cmd_put(1, cmd);
  return (1);
}
