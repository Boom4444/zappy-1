/*
** list.c for zappy in /home/ignatiev/Projects/zappy
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.net>
**
** Started on  Wed Jun 05 19:21:23 2013 oleg kuznietsov
** Last update Sat Jul 13 18:28:09 2013 oleg kuznietsov
*/

#include "list.h"
#include <stdlib.h>

t_list		*list_init()
{
  t_list	*list;

  if ((list = (t_list*)malloc(sizeof(t_list))) != NULL)
    {
      list->len = 0;
      list->head = NULL;
      list->tail = NULL;
      return (list);
    }
  return (NULL);
}

t_item		*list_get_head(t_list *list)
{
  if (list != NULL)
    return (list->head);
  return (NULL);
}

t_item		*list_get_tail(t_list *list)
{
  if (list != NULL)
    return (list->tail);
  return (NULL);
}

t_list		*list_delete(t_list *list)
{
  t_item	*next;
  t_item	*current;

  if (list == NULL)
    return (list);
  current = list_get_head(list);
  while (current != NULL)
    {
      next = current;
      free(current);
      current = next;
    }
  free(list);
  return (NULL);
}
