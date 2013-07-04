/*
** list.h for zappy in /home/ignatiev/Projects/zappy
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.net>
**
** Started on  Wed Jun  05 18:48:34 2013 oleg kuznietsov
** Last update Thu Jul 04 20:40:02 2013 ivan ignatiev
*/

#ifndef LIST_H_
# define LIST_H_

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

int     item_pf(t_list *list, void *data, int size);
int     item_pb(t_list *list, void *data, int size);
void    item_delete(t_list *list, t_item *item);
t_item  *item_create(void *src_content, int content_size);
t_item  *item_init();
t_list  *list_init();
void    list_delete(t_list *list);
int     list_iter(t_list *list, void (*f)(void *, int));
int     list_mem(t_list *list, void *content, int size);

#endif /* LIST_H_ */
