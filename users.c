/*
** users.c for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Sat Apr 27 14:16:14 2013 ivan ignatiev
** Last update Wed Jul 10 20:37:39 2013 ivan ignatiev
*/

#include    "main.h"
#include    "list.h"
#include    "options.h"
#include    "trantor.h"
#include    "server.h"
#include	"users.h"
#include    "error.h"
#include    "item.h"
#include    "answer.h"

t_user      *user_create()
{
    t_user  *user;

    if ((user = (t_user*)malloc(sizeof(t_user))) != NULL)
    {
        user->protocol = NONE_PROTO;
        user->connected = PRE_CONNECTED;
        user->request = NULL;
        user->request_buf = NULL;
        user->addrlen = sizeof(struct sockaddr_in);
    }
    return (user);
}

void                user_player_place(t_user_player *player, int x, int y, int orientation)
{
    int             i;

    player->connected = CONNECTED;
    player->protocol = CLI_PROTO;
    player->posx = x;
    player->posy = y;
    player->orientation = orientation;
    player->tick = 0;
    player->level = 1;
    player->request_counter = 0;
    player->inventory[FOOD] = 10;
    i = 1;
    while (i < ARTICLES_LIMIT)
    {
        player->inventory[i] = 0;
        ++i;
    }
}

t_user_player       *user_player_init(t_user *user, t_team *team, t_world *w, t_server *s)
{
    (void) s;
    t_user_player   *player;

    if ((player = T_PLAYER(realloc(user, sizeof(t_user_player)))) != NULL)
    {
        user_player_place(player,
                _MOD(rand(), w->width),
                _MOD(rand(), w->height),
                _MOD(rand(), 4)
                );
        player->team = team;
        item_pf(w->surface[player->posy][player->posx].players,
                (void*)player, sizeof(t_user_player));
        return (player);
    }
    error_show("user_player_init", "malloc", "Unable allocate memory for players");
    return (NULL);
}

t_user_player       *user_player_egg(t_user *user, t_team *team, t_world *w, t_server *s)
{
    t_user_egg      *egg;
    t_user_player   *player;
    t_item          *current;

    current = s->client_list->head;
    while (current != NULL)
    {
        if (T_USER(current->cont)->protocol == EGG_PROTO
                && T_EGG(current->cont)->hatched
                && T_EGG(current->cont)->team == team)
        {
            if ((player = realloc(user, sizeof(t_user_player))) != NULL)
            {
                user_player_place(player,
                        T_EGG(current->cont)->posx,
                        T_EGG(current->cont)->posy,
                        _MOD(rand(), 4)
                        );
                player->team = T_EGG(current->cont)->team;
                item_pf(w->surface[player->posy][player->posx].players,
                        (void*)player, sizeof(t_user_player));
                egg = T_EGG(current->cont);
                item_delete(s->client_list, current);
                log_show("user_player_egg", "", "Egg %d become a player", egg->number);
                free(egg);
                return (player);
            }
            error_show("user_player_init", "malloc", "Unable allocate memory for players");
            return (NULL);
        }
        current = current->next;
    }
    return (NULL);

}

t_user_egg      *user_egg_init(t_user_player *parent, t_server *s)
{
    t_user_egg  *egg;

    if ((egg = malloc(sizeof(t_user_egg))) != NULL)
    {
        egg->connected = DISCONNECTED;
        egg->protocol = EGG_PROTO;
        egg->clientfd = -1;
        egg->hatched = 0;
        egg->life = LIFE_UNIT * 10 * s->options.tdelay;
        egg->posx = parent->posx;
        egg->posy = parent->posy;
        egg->parent_number = parent->number;
        egg->team = parent->team;
        return (egg);
    }
    error_show("user_player_init", "malloc", "Unable allocate memory for eggs");
    return (NULL);
}

t_user_graph        *user_graph_init(t_user *user)
{
    t_user_graph    *graph;

    if ((graph = realloc(user, sizeof(t_user_graph))) != NULL)
    {
        graph->protocol = GRAPHIC_PROTO;
        graph->connected = CONNECTED;
        log_show("user_graph_init", "", "Graphic client created");
        return (graph);
    }
    error_show("user_graph_init", "malloc", "Unable allocate memory for GFX clients");
    return (NULL);
}

void        user_destroy(t_user *user, t_server *s, t_world *w)
{
    char    response[ANSWER_SIZE];

    item_delete_by_content(s->client_list, (void*)user);
    if (user->protocol == CLI_PROTO)
    {
        cli_answer(T_PLAYER(user), s, "mort\n");
        sprintf(response, "pdi %d\n", T_PLAYER(user)->number);
        cli_answer_to_all_graph(s, response);
        ++(T_PLAYER(user)->team->limit);
        item_delete_by_content(w->surface[T_PLAYER(user)->posy][T_PLAYER(user)->posx].players, (void*)user);
        log_show("user_destroy", "", "Player %d disconnected and removed", T_PLAYER(user)->number);
        close(user->clientfd);
        free(user);
        return ;
    }
    else if (user->protocol == GRAPHIC_PROTO)
    {
        close(user->clientfd);
        free(user);
        log_show("user_destroy", "", "GFX Client disconnected and removed");
        return ;
    }
    close(user->clientfd);
    free(user);
    log_show("user_destroy", "", "Client disconnected and removed");
}

void        users_life_proccess(t_server *s, t_world *w)
{
    t_item  *current;
    t_item  *next;

    current = s->client_list->head;
    while (current != NULL)
    {
        next = current->next;
        if (T_USER(current->cont)->protocol == CLI_PROTO)
        {
            --(T_PLAYER(current->cont)->life);
            if (T_PLAYER(current->cont)->life <= 0)
            {
                T_PLAYER(current->cont)->life = LIFE_UNIT * s->options.tdelay;
                --(T_PLAYER(current->cont)->inventory[FOOD]);
                if (T_PLAYER(current->cont)->inventory[FOOD] <= 0)
                {
                    log_show("users_life_process", "", "PLayer %d finished his food", T_PLAYER(current->cont)->number);
                    user_destroy(T_USER(current->cont), s, w);
                }
            }
        }
        else if (T_USER(current->cont)->protocol == EGG_PROTO)
        {
            --(T_EGG(current->cont)->life);
            if (T_EGG(current->cont)->life <= 0)
            {
                --(T_EGG(current->cont)->team->limit);
                log_show("users_life_process", "", "Egg's spirit %d goes away", T_EGG(current->cont)->number);
                free(current->cont);
                item_delete(s->client_list, current);
            }
        }
        current = next;
    }
}

t_team      *team_create(char *name, t_server *s)
{
    t_team  *team;

    if ((team = (t_team*)malloc(sizeof(t_team))) != NULL)
    {
        strncpy(team->name, name, NAME_LIMIT);
        team->name[NAME_LIMIT] = '\0';
        team->members = 0;
        team->limit = s->options.cmax;
        log_show("team_create", "", "Team created : '%s'", team->name);
    }
    return (team);
}

t_team          *team_search(t_list *team_list, char *team_name)
{
    t_item      *current;

    current = team_list->head;
    while (current != NULL)
    {
        if (strcmp(T_TEAM(current)->name, team_name) == 0)
            return (T_TEAM(current));
        current = current->next;
    }
    return (NULL);
}

t_list      *team_list_init(t_server *s, t_list *team_names)
{
    t_team  *team;
    t_item  *current;

    s->team_list = list_init();
    current = team_names->head;
    while (current != NULL)
    {
        team = team_create((char*)(current->cont), s);
        item_pf(s->team_list, (void*)team, sizeof(t_team));
        current = current->next;
    }
    return (s->team_list);
}

void        team_destroy(t_team *team)
{
    (void) team;
}
