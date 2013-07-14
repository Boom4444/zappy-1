/*
** gc_1.c for Zappy in /home/el/Zappy/GClient
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Sat Jul  13 20:35:24 2003 oleg kuznietsov
** Last update Sat May  13 20:35:24 2001 oleg kuznietsov
*/

#include "graph_commands.h"

int   gcmd_sgt(char *cmd, t_pm *pm)
{
  ping_save(pm);
  cmd_put(cmd);
  return (1);
}

int   gcmd_seg(char *cmd, t_pm *pm)
{
  ping_save(pm);
  cmd_put(cmd);
  return (1);
}

int   gcmd_smg(char *cmd, t_pm *pm)
{
  ping_save(pm);
  cmd_put(cmd);
  return (1);
}

int   gcmd_suc(char *cmd, t_pm *pm)
{
  if (nsp_get(cmd) != 0)
  {
    cmd_send(pm, "mct\n");
    return (-1);
  }
  ping_save(pm);
  cmd_put(cmd);
  return (1);
}

int   gcmd_sbp(char *cmd, t_pm *pm)
{
  if (nsp_get(cmd) != 0)
  {
    cmd_send(pm, "mct\n");
    return (-1);
  }
  ping_save(pm);
  cmd_put(cmd);
  return (1);
}
