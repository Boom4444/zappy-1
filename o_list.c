
#include "list.h"
#include <stdlib.h> /* malloc, free */

t_list  *new_list_by_default()
{
  t_list  *list = NULL;

  if ((list = (t_list *) malloc(1 * sizeof(*list))) == NULL)
    return NULL;
  list->len = 0;
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void    delete_list(t_list *list)
{
  t_item  *item = list->head;
  t_item  *current = item;

  if (list != NULL)
  {
    while (current != NULL)
    {
      if (item->content != NULL)
        free(item->content);
      free(item);
      current = current->next;
      item = current;
    }
    free(list);
  }
}

int     list_iter(t_list *list, void (*f)(void *, int))
{
  t_item  *current = NULL;

  if (list != NULL && f != NULL)
  {
    current = list->head;
    while (current != NULL)
    {
      f(current->content, current->size);
      current = current->next;
    }
    return 1;
  }
  return -1;
}

t_list  *list_map(t_list *list, t_item *(*f)(void *, int))
{
  t_list  *ret = NULL;
  t_item  *current = NULL;
  t_item  *tmp = NULL;

  ret = new_list_by_default();
  if (list == NULL || ret == NULL)
    return NULL;
  current = list->head;
  while (current != NULL)
  {
    tmp = f(current->content, current->size);
    list_add_back_real(ret, tmp);
    current = current->next;
  }
  return ret;
}

int     list_mem(t_list *list, void *content, int size)
{
  int     i;
  t_item  *current = NULL;

  if (size == 0 || content == NULL)
    return -1;
  if (list != NULL)
  {
    current = list->head;
    while (current != NULL)
    {
      if (current->size == size)
      {
        for (i = 0; i < size; ++i)
        {
          if (((char*)content)[i] != ((char*)current->content)[i])
            return -1;
        }
      }
      current = current->next;
    }
  }
  return 1;
}