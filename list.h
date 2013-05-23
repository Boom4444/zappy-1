#ifndef LIST_H_
# define LIST_H_

typedef struct  s_item
{
  void          *content;
  int           size;
  struct s_item *prev;
  struct s_item *next;
} t_item;

typedef struct  s_list
{
  int    len;
  t_item *head;
  t_item *tail;
} t_list;

t_item  *new_item_by_param(void *src_content, int content_size);

void    delete_item(t_list *list, t_item *item);

// ------------------------------- item ^ --------------------------------------

t_list  *new_list_by_default();

void    delete_list(t_list *list);

int     list_iter(t_list *list, void (*f)(void *, int));

int     list_mem(t_list *list, void *content, int size);

t_list  *list_map(t_list *list, t_item *(*f)(void *, int));

// ----------------------------- o_list ^ --------------------------------------

int     list_add_front(t_list *list, void *data, int size);

int     list_add_back(t_list *list, void *data, int size);

// ----------------------------- p_list ^ --------------------------------------

#endif /* LIST_H_ */
