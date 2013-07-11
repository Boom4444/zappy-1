/*
** item.c for zappy in /home/ignatiev/Projects/zappy
**
** Made by oleg kuznietsov
** Login   <kuznet_o@epitech.net>
**
** Started on  Wed Jun  05 19:21:34 2013 oleg kuznietsov
** Last update Thu Jul 11 18:28:15 2013 ivan ignatiev
*/

#include    "main.h"
#include    "list.h"
#include    "error.h"


t_item    *item_init()
{
  t_item  *item;

  if ((item = malloc(sizeof(t_item))) != NULL)
  {
      item->cont = NULL;
      item->prev = NULL;
      item->next = NULL;
      item->size = 0;
      return (item);
  }
  error_show("item_init", "malloc", "Unable to allocate memory for item");
  return (NULL);
}

t_item    *item_create(void *src_content, int content_size)
{
    t_item  *item;

    if ((item = item_init()) != NULL)
    {
        item->cont = src_content;
        item->size = content_size;
    }
    return (item);
}

int       item_pf(t_list *list, void *data, int size)
{
  t_item  *item;

  item = item_create(data, size);
  if (list == NULL || item == NULL)
    return (-1);
  item->prev = NULL;
  item->next = list->head;
  if (list->head != NULL)
    list->head->prev = item;
  if (list->tail == NULL)
    list->tail = item;
  list->head = item;
  list->len += 1;
  return (1);
}

int       item_pb(t_list *list, void *data, int size)
{
  t_item  *item;

  item = item_create(data, size);
  if (list == NULL || item == NULL)
    return (-1);
  item->prev = list->tail;
  item->next = NULL;
  if (list->tail != NULL)
    list->tail->next = item;
  if (list->head == NULL)
    list->head = item;
  list->tail = item;
  list->len += 1;
  return (1);
}

void        item_delete(t_list *list, t_item *item)
{
    t_item  *current;

    if (list != NULL && item != NULL)
    {
        current = list->head;
        while (current != NULL)
        {
            if (current == item)
            {
                if (list->head == current)
                    list->head = current->next;
                if (list->tail == current)
                    list->tail = current->prev;
                if (current->prev != NULL)
                    current->prev->next = current->next;
                if (current->next != NULL)
                    current->next->prev = current->prev;
                free(item);
                list->len -= 1;
                return ;
            }
            current = current->next;
        }
    }
}

void        item_delete_by_content(t_list *list, void *cont)
{
    t_item  *current;

    if (list != NULL && cont != NULL)
    {
        current = list->head;
        while (current != NULL)
        {
            if (current->cont == cont)
            {
                if (list->head == current)
                    list->head = current->next;
                if (list->tail == current)
                    list->tail = current->prev;
                if (current->prev != NULL)
                    current->prev->next = current->next;
                if (current->next != NULL)
                    current->next->prev = current->prev;
                free(current);
                list->len -= 1;
                return ;
            }
            current = current->next;
        }
    }
}
