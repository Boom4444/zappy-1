/*
** gc_1.c for Zappy in /home/el/Zappy/GClient
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Sat Jul  13 20:35:24 2013 oleg kuznietsov
** Last update Sat May  13 20:35:24 2013 oleg kuznietsov
*/

#include "graph_commands.h"

int   gcmd_pic(char *cmd, t_pm *pm)
{
  ping_save(pm);
  cmd_put(cmd);
  return (1);
}

int   gcmd_pie(char *cmd, t_pm *pm)
{
  if (nsp_get(cmd) != 3)
  {
    cmd_send(pm, "mct\n");
    return (-1);
  }
  ping_save(pm);
  cmd_put(cmd);
  return (1);
}

int   gcmd_pfk(char *cmd, t_pm *pm)
{
  if (nsp_get(cmd) != 1)
  {
    cmd_send(pm, "mct\n");
    return (-1);
  }
  ping_save(pm);
  cmd_put(cmd);
  return (1);
}

int   gcmd_pdr(char *cmd, t_pm *pm)
{
  if (nsp_get(cmd) != 2)
  {
    cmd_send(pm, "mct\n");
    return (-1);
  }
  ping_save(pm);
  cmd_put(cmd);
  return (1);
}

int   gcmd_pgt(char *cmd, t_pm *pm)
{
  if (nsp_get(cmd) != 2)
  {
    cmd_send(pm, "mct\n");
    return (-1);
  }
  ping_save(pm);
  cmd_put(cmd);
  return (1);
}
