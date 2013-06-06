/*
** list.h for server in /home/hero/zappy/server
** 
** Made by Oleg Kuznietsov
** Login   <kuznet_o@epitech.net>
** 
** Started on  Thu May 30 13:37:36 2013 Oleg Kuznietsov
** Last update Thu Jun 06 00:14:45 2013 Marin Alcaraz
*/

#ifndef LIST_H_
# define LIST_H_

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

typedef struct  s_item
{
  void          *cont;
  int           size;
  struct s_item *prev;
  struct s_item *next;
}               t_item;

typedef struct  s_list
{
  int           len;
  t_item        *head;
  t_item        *tail;
}               t_list;

void    item_pf(t_list *list, void *data, int size);
void    item_pb(t_list *list, void *data, int size);
void    item_delete(t_list *list, t_item *item);
t_item  *item_create(void *src_content, int content_size);
t_item  *item_init();
t_list  *list_init();
void    list_delete(t_list *list);
void    list_iter(t_list *list, void (*f)(void *, int));
int     list_mem(t_list *list, void *content, int size);

#endif /* LIST_H_ */
