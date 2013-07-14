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
#include "gclient_funcs.h"
#include "gclient_ping.h"

int   gcmd_ppo(char *cmd, t_pm *pm)
{
  if (nsp_get(cmd) != 5)
  {
    cmd_send(pm, "mct\n");
    return (-1);
  }
  ping_save(pm);
  cmd_put(cmd);
  return (1);
}

int   gcmd_plv(char *cmd, t_pm *pm)
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

int   gcmd_pin(char *cmd, t_pm *pm)
{
  if (nsp_get(cmd) != 10)
  {
    cmd_send(pm, "mct\n");
    return (-1);
  }
  ping_save(pm);
  cmd_put(cmd);
  return (1);
}

int   gcmd_pex(char *cmd, t_pm *pm)
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

int   gcmd_pbc(char *cmd, t_pm *pm)
{
  ping_save(pm);
  cmd_put(cmd);
  return (1);
}
