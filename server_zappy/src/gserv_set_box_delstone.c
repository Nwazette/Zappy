/*
** gserv_set_box_delstone.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:05:03 2011 Julien Di Marco
** Last update Thu Jun 30 05:05:03 2011 Julien Di Marco
*/

#include		<stdlib.h>
#include		"stone.h"
#include		"tserver.h"
#include		"server_zappy.h"

extern t_server 	*gserv;

static bool		match_stone(void *data, void *stone)
{
  return (((t_stone *)data)->type == *((e_stone *)stone));
}

bool			set_box_delstone(uint x, uint y,
					e_stone type, uint nb)
{
  t_box 		*box;
  t_stone 		*stone;

  if (!(box = get_box(x, y)) ||
      !(stone = get_data_as_arg(box->stones, match_stone, &type)))
    return (false);
  if (stone->nb < nb)
    stone->nb = 0;
  else
    stone->nb -= nb;
  return (true);
}