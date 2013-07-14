/*
** gclient_funcs.h for Zappy in /home/el/Zappy/GClient
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Fri Jun 24 19:45:50 2003 oleg kuznietsov
** Last update Wed May 12 14:58:18 2001 oleg kuznietsov
*/

#ifndef GCLIENT_FUNCS_H_
# define GCLIENT_FUNCS_H_

# include <sys/types.h>
# include "gclient.h"

void  cmd_send(t_pm *pm, char *cmd);
int   nsp_get(char *str);
void  cmd_put(int i, char *cmd);
void  select_monitor(fd_set *fd_rs, t_ppo *p, t_pm *pm);

#endif /* !GCLIENT_FUNCS_H_ */
