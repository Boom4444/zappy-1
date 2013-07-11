/*
** item.h for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Thu Jul 04 17:14:00 2013 ivan ignatiev
** Last update Thu Jul 11 18:27:55 2013 ivan ignatiev
*/

#ifndef ITEM_H_
# define ITEM_H_

t_item    *item_init();
t_item    *item_create(void *src_content, int content_size);
int       item_pf(t_list *list, void *data, int size);
int       item_pb(t_list *list, void *data, int size);
void        item_delete(t_list *list, t_item *item);
void        item_delete_by_content(t_list *list, void *item);

#endif /* !ITEM_H_ */
