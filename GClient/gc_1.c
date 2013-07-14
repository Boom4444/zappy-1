/*
** gc_1.c for Zappy in /home/el/Zappy/GClient
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Sat Jul  13 20:35:24 2013 oleg kuznietsov
** Last update Sun Jul 14 22:00:50 2013 ivan ignatiev
*/

#include	"graph_commands.h"
#include	"gclient_funcs.h"
#include	"gclient_ping.h"

int		gcmd_ppo(char *cmd, t_pm *pm)
{
  if (nsp_get(cmd) != 5)
    {
      cmd_put(-1, cmd);
      cmd_send(pm, "mct\n");
      return (-1);
    }
  ping_save(pm);
  cmd_put(1, cmd);
  return (1);
}

int		gcmd_plv(char *cmd, t_pm *pm)
{
  if (nsp_get(cmd) != 2)
    {
      cmd_put(-1, cmd);
      cmd_send(pm, "mct\n");
      return (-1);
    }
  cmd_put(1, cmd);
  return (1);
}

int		gcmd_pin(char *cmd, t_pm *pm)
{
  if (nsp_get(cmd) != 10)
    {
      cmd_put(-1, cmd);
      cmd_send(pm, "mct\n");
      return (-1);
    }
  ping_save(pm);
  cmd_put(1, cmd);
  return (1);
}

int		gcmd_pex(char *cmd, t_pm *pm)
{
  if (nsp_get(cmd) != 1)
    {
      cmd_put(-1, cmd);
      cmd_send(pm, "mct\n");
      return (-1);
    }
  ping_save(pm);
  cmd_put(1, cmd);
  return (1);
}

int		gcmd_pbc(char *cmd, t_pm *pm)
{
  ping_save(pm);
  cmd_put(1, cmd);
  return (1);
}
