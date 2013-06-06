/*
** list.h for Zappy in /home/el/Zappy/Main
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.net>
**
** Started on  Wed Jun  05 18:48:34 2013 oleg kuznietsov
** Last update Thu Jun  06 22:26:29 2013 oleg kuznietsov
*/

#ifndef LIST_H_
# define LIST_H_

#include <stdlib.h>
#include <string.h>

typedef struct  s_item
{
  void          *cont;
  size_t        size;
  struct s_item *prev;
  struct s_item *next;
}               t_item;

typedef struct  s_list
{
  size_t        len;
  t_item        *head;
  t_item        *tail;
}               t_list;

/*
**                   item.c
*/
int     item_pf(t_list *list, void *data, int size);

int     item_pb(t_list *list, void *data, int size);

void    item_delete(t_list *list, t_item *item);

t_item  *item_create(void *src_content, int content_size);

t_item  *item_init();

/*
**                   list.c
*/
t_list  *list_init();

void    list_delete(t_list *list);

int     list_iter(t_list *list, void (*f)(void *, int));

int     list_mem(t_list *list, void *content, int size);

#endif /* LIST_H_ */
