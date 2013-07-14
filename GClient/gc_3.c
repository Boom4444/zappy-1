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


int   gcmd_pdi(char *cmd, t_pm *pm)
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

int   gcmd_enw(char *cmd, t_pm *pm)
{
  if (nsp_get(cmd) != 4)
  {
    cmd_send(pm, "mct\n");
    return (-1);
  }
  ping_save(pm);
  cmd_put(cmd);
  return (1);
}

int   gcmd_eht(char *cmd, t_pm *pm)
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

int   gcmd_ebo(char *cmd, t_pm *pm)
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

int   gcmd_edi(char *cmd, t_pm *pm)
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
