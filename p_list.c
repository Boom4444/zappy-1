#include "list.h"
#include <stddef.h> // NULL

int  list_add_front_real(t_list *list, t_item *item)
{
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

int  list_add_back_real(t_list *list, t_item *item)
{
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

int   list_add_front(t_list *list, void *data, int size)
{
  return list_add_front_real(list, new_item_by_param(data, size));
}

int   list_add_back(t_list *list, void *data, int size)
{
  return list_add_back_real(list, new_item_by_param(data, size));
}