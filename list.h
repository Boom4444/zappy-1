/*
** list.h for zappy in /home/ignatiev/Projects/zappy
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.net>
**
** Started on  Wed Jun  05 18:48:34 2013 oleg kuznietsov
** Last update Sat Jul 13 18:27:12 2013 ivan ignatiev
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct	s_item
{
  void		*cont;
  size_t	size;
  struct s_item	*prev;
  struct s_item	*next;
}		t_item;

typedef struct	s_list
{
  size_t	len;
  t_item	*head;
  t_item	*tail;
}		t_list;

t_list	*list_init(void);
t_list	*list_delete(t_list *list);
t_item	*list_get_head(t_list *list);
t_item	*list_get_tail(t_list *list);

#endif /* LIST_H_ */
