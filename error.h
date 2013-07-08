/*
** error.h for zappy in /home/ignatiev/Projects/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Fri Mar 15 16:48:12 2013 Marin Alcaraz
** Last update Mon Jul 08 15:34:49 2013 ivan ignatiev
*/

#ifndef ERROR_H_
# define ERROR_H_

int         error_show(char *loc, char *func, char *msg, ...);
int         log_show(char *loc, char *func, char *msg, ...);

#endif /* !ERROR_H_ */
