/*
** list.c for Zappy in /home/el/Zappy/Main
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.net>
**
** Started on  Wed Jun  05 19:21:23 2013 oleg kuznietsov
** Last update Thu Jun  06 22:23:26 2013 oleg kuznietsov
*/

#include "list.h"

t_list    *list_init()
{
  t_list  *list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  list->len = 0;
  list->head = NULL;
  list->tail = NULL;
  return (list);
}

void      list_delete(t_list *list)
{
  t_item  *item;
  t_item  *current;

  item = list->head;
  current = item;
  if (list != NULL)
  {
    while (current != NULL)
    {
      if (item->cont != NULL)
        free(item->cont);
      free(item);
      current = current->next;
      item = current;
    }
    free(list);
  }
}

int       list_iter(t_list *list, void (*f)(void *, int))
{
  t_item  *current;

  current = NULL;
  if (list == NULL || f == NULL)
    return -1;
  current = list->head;
  while (current != NULL)
  {
    f(current->cont, current->size);
    current = current->next;
  }
  return 1;
}

int       list_mem(t_list *list, void *content, int size)
{
  int     i;
  t_item  *current;

  i = 0;
  current = NULL;
  if (size <= 0 || content == NULL || list == NULL)
    return -1;
  current = list->head;
  while (current != NULL)
  {
    if (current->size == (size_t)size)
    {
      while (i < size)
      {
        if (((char*)content)[i] != ((char*)current->cont)[i])
          return -1;
        ++i;
      }
    }
    current = current->next;
  }
  return 1;
}
