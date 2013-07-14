#ifndef GCLIENT_ERRORS_H_
# define GCLIENT_ERRORS_H_

#include "gclient.h"

void  cp_error(t_pm *pm, char *loc, char *msg);
void  ts_error(char *loc, t_pm *pm, int ret);
int   bp_error(t_pm *pm);

#endif /* !GCLIENT_ERRORS_H_ */
