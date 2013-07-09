/*
** answer.h for zappy in /home/ignatiev/Projects/zappy
** 
** Made by ivan ignatiev
** Login   <ignati_i@epitech.net>
** 
** Started on  Tue Jun 25 17:18:35 2013 ivan ignatiev
** Last update Mon Jul 08 20:22:48 2013 ivan ignatiev
*/

#ifndef ANSWER_H_
# define ANSWER_H_

# define T_ANSWER(answer)               ((t_answer*)(answer->cont))
# define ANSWER_SIZE                    512

typedef struct      s_answer
{
    t_user_player   *user;
    char            *message;
}                    t_answer;

t_answer        *cli_answer_create(t_user_player *user, char *message);
void            cli_answer(t_user_player *user, t_server *server, char *message);
void            cli_answer_to_graph(t_user_graph *user, char *message);
void            cli_answer_to_all_graph(t_server *server, char *message);
void            cli_answers_process(t_server *s, t_world *w, struct timeval *start,
                                        unsigned long long tick_size);

#endif /* !ANSWER_H_ */
