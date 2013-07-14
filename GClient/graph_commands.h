/*
** graph_command.h for zappy in /home/hero/zappy
** 
** Made by Ivan Ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Wed Jun 12 17:02:27 2003 Marin Alcaraz
** Last update Mon May 08 13:32:36 2001 oleg kuznietsov
*/

#ifndef GRAPH_COMMAND_H_
# define	GRAPH_COMMAND_H_

#include "gclient.h"

typedef int (*t_graph_func)(char *cmd, t_pm *pm);

typedef struct  s_graph_cmd
{
  char          *scmd;
  t_graph_func  func;
}               t_gcmd;

int   gcmd_msz(char *cmd, t_pm *pm);
int   gcmd_bct(char *cmd, t_pm *pm);
int   gcmd_tna(char *cmd, t_pm *pm);
int   gcmd_pnw(char *cmd, t_pm *pm);
int   gcmd_ppo(char *cmd, t_pm *pm);
int   gcmd_plv(char *cmd, t_pm *pm);
int   gcmd_pin(char *cmd, t_pm *pm);
int   gcmd_pex(char *cmd, t_pm *pm);
int   gcmd_pbc(char *cmd, t_pm *pm);
int   gcmd_pic(char *cmd, t_pm *pm);
int   gcmd_pie(char *cmd, t_pm *pm);
int   gcmd_pfk(char *cmd, t_pm *pm);
int   gcmd_pdr(char *cmd, t_pm *pm);
int   gcmd_pgt(char *cmd, t_pm *pm);
int   gcmd_pdi(char *cmd, t_pm *pm);
int   gcmd_enw(char *cmd, t_pm *pm);
int   gcmd_eht(char *cmd, t_pm *pm);
int   gcmd_ebo(char *cmd, t_pm *pm);
int   gcmd_edi(char *cmd, t_pm *pm);
int   gcmd_sgt(char *cmd, t_pm *pm);
int   gcmd_seg(char *cmd, t_pm *pm);
int   gcmd_smg(char *cmd, t_pm *pm);
int   gcmd_suc(char *cmd, t_pm *pm);
int   gcmd_sbp(char *cmd, t_pm *pm);

#endif	/* !GRAPH_COMMAND_H_ */
