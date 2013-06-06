/*
** item.c for Zappy in /home/el/Zappy/Main
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.net>
**
** Started on  Wed Jun  05 19:21:34 2013 oleg kuznietsov
** Last update Thu Jun  06 21:45:36 2013 oleg kuznietsov
*/

#include "list.h"

t_item  *item_init(t_item *item)
{
  if ((item = malloc(sizeof(t_item))) == NULL)
    return (NULL);
  item->cont = NULL;
  item->prev = NULL;
  item->next = NULL;
  item->size = 0;
  return (item);
}

t_item    *item_create(void *src_content, int content_size)
{
  t_item  *item;

  item = item_init(item);
  if (src_content == NULL || content_size <= 0)
    return (NULL);
  if ((item->cont = malloc(content_size)) == NULL)
    return (NULL);
  item->cont = memcpy(item->cont, src_content, content_size);
  item->size = content_size;
  return (item);
}

int       item_pf(t_list *list, void *data, int size)
{
  t_item  *item;

  item = item_create(data, size);
  if (list == NULL || item == NULL)
    return -1;
  item->prev = NULL;
  item->next = list->head;
  if (list->head != NULL)
    list->head->prev = item;
  if (list->tail == NULL)
    list->tail = item;
  list->head = item;
  list->len += 1;
  return 1;
}

int       item_pb(t_list *list, void *data, int size)
{
  t_item  *item;

  item = item_create(data, size);
  if (list == NULL || item == NULL)
    return -1;
  item->prev = list->tail;
  item->next = NULL;
  if (list->tail != NULL)
    list->tail->next = item;
  if (list->head == NULL)
    list->head = item;
  list->tail = item;
  list->len += 1;
  return 1;
}

void      item_delete(t_list *list, t_item *item)
{
  t_item  *current = NULL;

  if (list != NULL && item != NULL)
  {
    current = list->head;
    while (current != NULL)
    {
      if (current == item)
      {
        if (current->prev != NULL)
          current->prev->next = current->next;
        if (current->next != NULL)
          current->next->prev = current->prev;
        if (item->cont != NULL)
          free(item->cont);
        free(item);
        list->len -= 1;
      }
      current = current->next;
    }
  }
}
