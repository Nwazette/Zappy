/*
** zappy_protocol.h for  in /home/solvik/tek2/proj/Zappy/server_zappy/modules/zappy_protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Wed Jun 29 10:24:19 2011 solvik blum
** Last update Wed Jun 29 13:02:16 2011 solvik blum
*/

#ifndef		ZAPPY_PROTOCOL_H_
# define	ZAPPY_PROTOCOL_H_

int		zappy_avance(t_fds *, char *);
int		zappy_droite(t_fds *, char *);
int		zappy_gauche(t_fds *, char *);
int		zappy_voir(t_fds *, char *);
int		zappy_inventaire(t_fds *, char *);
int		zappy_prend_objet(t_fds *, char *);
int		zappy_pose_objet(t_fds *, char *);
int		zappy_expulse(t_fds *, char *);
int		zappy_broadcast_texte(t_fds *, char *);
int		zappy_incantation(t_fds *, char *);
int		zappy_connect_nbr(t_fds *, char *);
int		zappy_fork(t_fds *, char *);

#endif		/* !ZAPPY_PROTOCOL_H_ */