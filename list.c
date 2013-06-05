/*
** list.c for Zappy in /home/el
** 
** Made by Oleg Kuznietsov
** Login   <kuznet_o@epitech.net>
** 
** Started on  Thu May 30 13:34:18 2013 Oleg Kuznietsov
** Last update Thu May 30 13:35:26 2013 Oleg Kuznietsov
*/

#include "list.h"

t_list    *list_init()
{
  t_list  *list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    {
      fprintf(stderr, "%s ERROR: %s\n", "malloc", "list_init");
      exit(EXIT_FAILURE);
    }
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

void      list_iter(t_list *list, void (*f)(void *, int))
{
  t_item  *current;

  current = NULL;
  if (list != NULL && f != NULL)
    {
      current = list->head;
      while (current != NULL)
	{
	  f(current->cont, current->size);
	  current = current->next;
	}
    }
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
      if (current->size == size)
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
