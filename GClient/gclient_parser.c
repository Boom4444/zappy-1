/*
** gclient_parser.c for Zappy in /home/el/Zappy/GClient
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.eu>
**
** Started on  Fri Jun 24 19:45:50 2003 oleg kuznietsov
** Last update Wed May 12 14:58:18 2001 oleg kuznietsov
*/

#include "gclient_parser.h"
#include "gclient_errors.h"
#include "graph_commands.h"
#include <string.h>

int   bp_guide(int bp_case, t_ppo *po, t_pm *pm)
{
  if (bp_case == 1)
    if (buf_process(po->rbuf, &po->tbuf[po->t],
                    0, po->i - po->t + 1) == -1)
      return (bp_error(pm));
  if (bp_case == 2)
    if ((po->plen = buf_process(&po->pbuf[po->plen], &po->tbuf[po->t],
                                  po->plen, po->i - po->t)) == -1)
      return (bp_error(pm));
  if (bp_case == 3)
    if (buf_process(&po->pbuf[po->plen], po->tbuf,
                    po->plen, po->i + 1) == -1)
      return (bp_error(pm));
  if (bp_case == 4)
  {
    if ((po->plen = buf_process(&po->pbuf[po->plen],
                                  po->tbuf, po->plen, po->i)) == -1)
      return (bp_error(pm));
  }
  return (1);
}

int   buf_process(char *dest, char *src, int dlen, int slen)
{
  int flen;

  flen = dlen + slen;
  if (flen > 255)
    return (-1);
  strncpy(dest, src, slen);
  dest[slen] = 0;
  return (flen);
}

int   pbuf_process(t_ppo *po, t_pm *pm)
{
  if (po->plen > 0)
  {
    while (po->i != po->tlen && po->tbuf[po->i] != '\n')
      ++po->i;
    if (po->i != po->tlen)
    {
      if (bp_guide(3, po, pm) == -1)
        return (-1);
      if (cmd_process(po->pbuf, pm) == -1)
        return (-1);
      ++po->i;
      po->t = po->i;
      po->plen = 0;
    }
    else if (bp_guide(4, po, pm) == -1)
      return (-1);
  }
  return (1);
}
