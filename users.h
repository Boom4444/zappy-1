/*
** users.h for zappy in /home/ignati_i/zappy/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Apr 27 17:03:35 2013 ivan ignatiev
** Last update Sun Jul 14 21:29:51 2013 ivan ignatiev
*/

#ifndef USERS_H_
# define USERS_H_

# define PRE_CONNECTED	2
# define CONNECTED	1
# define DISCONNECTED	0
# define NAME_LIMIT	256
# define ARTICLES_LIMIT	7
# define LIFE_UNIT	126
# define GRAPHIC_PROTO	100
# define CLI_PROTO	200
# define EGG_PROTO	300
# define NONE_PROTO	400
# define TOP		0
# define TOP_LEFT	1
# define MID_LEFT	2
# define BOT_LEFT	3
# define BOT_MID	4
# define BOT_RIGHT	5
# define MID_RIGHT	6
# define TOP_RIGHT	7
# define NORTH		0
# define EAST		1
# define SOUTH		2
# define WEST		3

# define T_USER(user)	((t_user *)(user))
# define T_PLAYER(user)	((t_user_player*)(user))
# define T_EGG(user)	((t_user_egg*)(user))
# define T_GRAPH(user)	((t_user_graph*)(user))
# define T_TEAM(team)	((t_team*)((team)->cont))

typedef struct		s_team
{
  char			name[NAME_LIMIT + 1];
  int			members;
  int			limit;
  int			v_flag;
}			t_team;

typedef struct		s_user
{
  int			clientfd;
  int			connected;
  int			protocol;
  struct sockaddr_in	addr;
  socklen_t		addrlen;
  char			*request;
  char			*request_buf;
}			t_user;

typedef struct		s_user_player
{
  int			clientfd;
  int			connected;
  int			protocol;
  struct sockaddr_in	addr;
  socklen_t		addrlen;
  char			*request;
  char			*request_buf;
  int			request_counter;
  int			life;
  int			posx;
  int			posy;
  int			level;
  int			orientation;
  unsigned long long	tick;
  t_team		*team;
  int			inventory[ARTICLES_LIMIT];
  int			number;
}			t_user_player;

typedef struct		s_user_egg
{
  int			clientfd;
  int			connected;
  int			protocol;
  struct sockaddr_in	addr;
  socklen_t		addrlen;
  char			*request;
  char			*request_buf;
  int			request_counter;
  int			life;
  int			posx;
  int			posy;
  unsigned long long	tick;
  int			number;
  int			parent_number;
  t_team		*team;
  int			hatched;
}			t_user_egg;

typedef struct		s_user_graph
{
  int			clientfd;
  int			connected;
  int			protocol;
  struct sockaddr_in	addr;
  socklen_t		addrlen;
  char			*request;
  char			*request_buf;
}			t_user_graph;

t_user		*user_create(void);
void		user_player_connected(t_user_player *u,
				      t_server *s, t_world *w);
t_user_player	*user_player_init(t_user *user, t_team *team,
				  t_world *w, t_server *s);
t_user_graph	*user_graph_init(t_user *user);
t_user_player	*user_player_egg(t_user *user, t_team *team,
				 t_world *w, t_server *s);
t_user_egg	*user_egg_init(t_user_player *parent, t_server *s);
int		user_destroy(t_user *user, t_server *s, t_world *w);
void		users_life_proccess(t_server *s, t_world *w);
t_team		*team_create(char *name, t_server *s);
t_team		*team_search(t_list *team_list, char *team_name);
t_list		*team_list_init(t_server *s, t_list *team_names);
int		user_graph_destroy(t_user_graph *user);
int		user_player_destroy(t_user_player *user,
				    t_server *s, t_world *w);
int		user_egg_destroy(t_user_egg *user, t_server *s);
void		user_player_place(t_user_player *player, int x, int y,
				  int orientation);

#endif /* !USERS_H_ */
