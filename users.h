/*
** users.h for zappy in /home/hero/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Apr 27 17:03:35 2013 ivan ignatiev
** Last update Sun Jul 07 14:53:27 2013 Marin Alcaraz
*/

#ifndef USERS_H_
# define USERS_H_

# define PRE_CONNECTED	2
# define CONNECTED		1
# define DISCONNECTED	0
# define NAME_LIMIT     256
# define ARTICLES_LIMIT 7

# define GRAPHIC_PROTO  100
# define CLI_PROTO      200
# define EGG_PROTO      300
# define NONE_PROTO     400

# define TOP         0
# define TOP_LEFT    1
# define MID_LEFT    2
# define BOT_LEFT    3
# define BOT_MID     4
# define BOT_RIGHT   5
# define MID_RIGHT   6
# define TOP_RIGHT   7

# define T_USER(user) ((t_user *)(user))
# define T_PLAYER(user) ((t_user_player*)(user))
# define T_GRAPH(user) ((t_user_graph*)(user))
# define T_TEAM(team) ((t_team*)((team)->cont))

typedef struct          s_team
{
    char                name[NAME_LIMIT];
    int                 members;
}                       t_team;

typedef struct		s_user
{
  int			        clientfd;
  int			        connected;
  int                   protocol;
  struct sockaddr_in	addr;
  socklen_t		        addrlen;
  char                  *request;
}			            t_user;

typedef struct          s_user_player
{
  int			        clientfd;
  int			        connected;
  int                   protocol;
  struct sockaddr_in	addr;
  socklen_t		        addrlen;
  char                  *request;

  int                   posx;
  int                   posy;
  int                   level;
  int                   direction;
  unsigned long long    tick;
  t_team                *team;
  int                   inventory[ARTICLES_LIMIT];
  int                   request_counter;
  int                   number;
}                       t_user_player;

typedef struct          s_user_graph
{
  int			        clientfd;
  int			        connected;
  int                   protocol;
  struct sockaddr_in	addr;
  socklen_t		        addrlen;
  char                  *request;
}                       t_user_graph;


t_user              *user_create();
t_user_player       *user_player_init(t_user *user, t_team *team, t_world *w, t_server *s);
t_user_graph        *user_graph_init(t_user *user);
void                user_destroy(t_user *user);
t_team              *team_create(char *name);
t_team              *team_search(t_list *team_list, char *team_name);
t_list              *team_list_init(t_list *team_list, t_list *team_names);
void                team_destroy(t_team *team);

#endif /* !USERS_H_ */
