/*
** graph_player.h for  in /home/seb/git/Zappy/server_zappy/src/graph_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Tue Jun 14 16:22:31 2011 seb
** Last update Wed Jul  6 00:26:02 2011 guillaume gelin
*/

#ifndef		GRAPH_PLAYER_H_
# define	GRAPH_PLAYER_H_

# include <stdbool.h>
# include "network.h"

bool graph_ppo(t_fds *, char *);
bool graph_plv(t_fds *, char *);
bool graph_pin(t_fds *, char *);

#endif		/* GRAPH_PLAYER_H_ */
