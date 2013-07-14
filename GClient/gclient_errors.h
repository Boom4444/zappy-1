/*
** gclient_errors.h for Zappy in /home/el/GitHub/zappy/GClient
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Sun Jul  14 20:47:50 2013 oleg kuznietsov
** Last update  Sun Jul  14 20:47:50 2013 oleg kuznietsov
*/

#ifndef GCLIENT_ERRORS_H_
# define GCLIENT_ERRORS_H_

# include "gclient.h"

void  cp_error(t_pm *pm, char *loc, char *msg);
void  ts_error(char *loc, t_pm *pm, int ret);
int   bp_error(t_pm *pm);

#endif /* !GCLIENT_ERRORS_H_ */
