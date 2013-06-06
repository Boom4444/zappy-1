/*
** users.c for my_irc in /home/ignatiev/Projects/my_irc
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Apr 27 14:16:14 2013 ivan ignatiev
** Last update Sun Apr 28 21:32:46 2013 ivan ignatiev
*/

#include	"users.h"

t_user		*user_create(void)
{
  t_user	*user;

  if ((user = (t_user*)malloc(sizeof(t_user))) == NULL)
    return (NULL);
  bzero(user, sizeof(t_user));
  return (user);
}

t_btree		*user_add(t_btree *users, t_user *user)
{
  t_btree	*root;

  root  = btree_insert_node(users, (t_data*)user);
  if (users == NULL)
    return (root);
  return (users);
}

t_btree		*user_remove(t_btree *users, t_user *user)
{
  close(user->clientfd);
  free(user);
  return (btree_remove_node(users, (t_data*)user));
}

t_btree		*user_remove_all(t_btree *users)
{
  t_user	*user;

  if (users == NULL)
    return (NULL);
  btree_free(users->left);
  btree_free(users->right);
  user = (t_user*)users->data;
  close(user->clientfd);
  free(users->data);
  free(users);
  return (NULL);
}

t_user		*user_find(t_btree *users, char *nick)
{
  int		cmp_result;

  if (users == NULL)
    return (NULL);
  cmp_result = strcasecmp(nick, users->data->name);
  if (cmp_result == 0)
    return ((t_user*)users->data);
  else if (cmp_result < 0)
    return (user_find(users->left, nick));
  else
    return (user_find(users->right, nick));
}
