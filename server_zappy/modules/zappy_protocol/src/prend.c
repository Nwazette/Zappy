/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Sat Jul  9 18:24:37 2011 solvik blum
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>

#include	"napi.h"

#include	"voir.h"
#include	"zappy_protocol.h"

static bool	prendre_action(t_player *p, char *obj)
{
  e_stone	stone;

  if ((stone = is_stone(obj)) != NONE)
    {
      if (!set_box_delstone(p->x, p->y, stone, 1) ||
	  !setplayer_addstone(p, stone, 1))
	return (false);
    }
  else if (!strcasecmp(obj, "nourriture"))
    {
      if (!set_box_delfood(p->x, p->y, 1) ||
	  !setplayer_addfood(p->id, 1))
	return (false);
    }
  else
    return (false);
  return (true);
}

int		zappy_prend(t_fds *c, char *cmd)
{
  t_player	*p;
  t_generic	*data;
  char		*obj;

  if (!c || !(p = *(t_player**)c) || !cmd ||
      !(strtok(cmd, " \t")) || !(obj = strtok(NULL, " \t")) ||
      !prendre_action(p, obj))
    {
      sends(c, "ko");
      return (false);
    }
  if (!(data = malloc(sizeof(*data))))
    {
      data->ui1 = p->id;
      data->ui2 = get_ressource_id(obj);
      event_relative_dispatch("TakeItem", data, 0);
    }
  sends(c, "ok");
  return (true);
}
