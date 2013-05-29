#include "list.h"
#include <stdlib.h> /* malloc, free */
#include <string.h> /* memcpy */

t_item  *new_item_by_default(t_item *item)
{
  if ((item = (t_item *)malloc(1 * sizeof(*item))) == NULL)
  	return NULL;
  item->content = NULL;
  item->prev = NULL;
  item->next = NULL;
  item->size = -1;
  return item;
}

t_item  *new_item_by_param(void *src_content, int content_size)
{
  t_item *item;

  if ((item = new_item_by_default(item)) == NULL)
    return NULL;
  if (src_content != NULL && content_size > 0)
  {
    if ((item->content = malloc(content_size)) != NULL)
    {
      item->content = memcpy(item->content, src_content, content_size);
      item->size = content_size;
    }
  }
  return item;
}

void    delete_item(t_list *list, t_item *item)
{
  t_item  *current = NULL;

  if (list != NULL)
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
        if (item->content != NULL)
          free(item->content);
        free(item);
        list->len -= 1;
      }
      current = current->next;
    }
  }
}