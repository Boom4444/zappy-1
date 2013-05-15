/*
** server.c for zappy in /home/hero/zappy
** 
** Made by Marin Alcaraz
** Login   <alcara_m@epitech.net>
** 
** Started on  Wed Apr 10 21:48:38 2013 Marin Alcaraz
** Last update Wed May 15 18:09:24 2013 Marin Alcaraz
*/

#include "server.h"
#include "error.h"
#include <string.h>

int             handle_client(int fd, char const *ip)
{
    char        buf[1024];
    int         rb;
    if((rb = read(fd, buf, 1024)) < 0)
        my_error("Error: client not available\n");
    write(fd, "TEST TEST", sizeof("TEST TEST"));
    (void) ip;
    return (0);
}

void            multiple_handler(struct sockaddr_in *s_in_client, int *ds)
{
  char          *client_ip;

  if (fork() == 0)
  {
    client_ip = strdup(inet_ntoa(s_in_client->sin_addr));
    printf("Client ip: %s \n", client_ip);
    while (42)
      handle_client(ds[1], client_ip);
    my_errorandclose("Child operations finished, closing\n", ds);
  }
  else
    close(ds[1]);
}

int                     server(int port)
{
  int                   ds[3];
  struct sockaddr_in    s_in;
  struct sockaddr_in    s_in_client;
  socklen_t             s_in_size;

  ds[2] = LIMIT;
  ds[0] = create_socket();
  s_in_size = sizeof(s_in_client);
  init_sockadd(&s_in, port, SERVER, "NA");
  if (bind(ds[0], (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    my_errorandclose("Error: unable to bind\n", ds);
  listen (ds[0], QUEUE_S);
  while (42)
  {
    ds[1] = accept(ds[0], (struct sockaddr *)&s_in_client, &s_in_size);
    if (ds[1] == -1)
      my_errorandclose("Error accepting the request\n", ds);
    multiple_handler(&s_in_client, ds);
  }
  my_errorandclose("Gracefully closing server connection\n", ds);
  return (0);
}
