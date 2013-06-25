/*
** proto.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Jun 12 16:34:40 2013 Marin Alcaraz
** Last update Tue Jun 25 17:16:32 2013 Marin Alcaraz
*/

#include    "proto.h"
#include    "error.h"

void        cli_parse(t_user *u, t_server *s, t_world *w)
{
    (void) (s);
    (void) (w);
    int     rb;
    char    buf[256];

    if ((rb = read(u->clientfd, buf, 256)) > 0)
    {
        buf[rb] = '\0';
        if (u->request == NULL && (u->request = (char*)malloc(sizeof(char) * strlen(buf))) != NULL)
            strcpy(u->request, buf);
        else if ((u->request = (char*)realloc(u->request, sizeof(char) * (strlen(buf) + strlen(u->request) + 1))) != NULL)
            strcat(u->request, buf);
        if (u->request != NULL && strchr(u->request, '\n') != NULL)
        {
            u->request = NULL;
        }
    }
}

void        graph_parse(t_user *u, t_server *s, t_world *w)
{
    (void) (s);
    (void) (w);
    int     rb;
    char    buf[256];

    if ((rb = read(u->clientfd, buf, 256)) > 0)
    {
        buf[rb] = '\0';
        printf("the GRAPH parser should run here\n");
    }
}

int         proto_parse(t_user *u, t_server *s, t_world *w)
{
    if (u->protocol == CLI_PROTO)
        cli_parse(u, s, w);
    else if (u->protocol == GRAPHIC_PROTO)
        graph_parse(u, s, w);
    return (0);
}

int         proto_define(t_user *u, t_world *w)
{
    int     rb;
    char    buf[256];

    (void) (w);
    /** TODO: GET COORDINATES **/
    if ((rb = read(u->clientfd, buf, 256)) > 0)
    {
        buf[rb] = '\0';

        if (strcmp(buf, "GRAPHIC\n") == 0)
            u->protocol = GRAPHIC_PROTO;
        else
        {
            strcpy(u->team, buf);
            u->protocol = CLI_PROTO;
        }
        u->connected = CONNECTED;
        return (0);
    }
    return (error_log("proto.c", "proto_define", "Error: Unable to read on client init"));
}
