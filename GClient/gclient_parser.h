#ifndef GCLIENT_PARSER_H_
# define GCLIENT_PARSER_H_

#include "gclient.h"

int   bp_guide(int bp_case, t_ppo *po, t_pm *pm);
int   buf_process(char *dest, char *src, int dlen, int slen);
int   pbuf_process(t_ppo *po, t_pm *pm);

#endif /* !GCLIENT_PARSER_H_*/
