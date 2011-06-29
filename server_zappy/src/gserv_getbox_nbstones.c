
#include		<stdlib.h>
#include		"stone.h"
#include		"tserver.h"
#include		"server_zappy.h"

extern t_server *	gserv;

static bool		match_stone(void * data, void * stone)
{
  return (((t_stone *)data)->type == *((e_stone *)stone));
}

uint			getbox_nbstones(uint x, uint y, e_stone type)
{
  t_box *		box;
  t_stone *		stone;

  if (!(box = get_box(x, y)) ||
      !(stone = get_data_as_arg(box->stones, match_stone, &type)))
    return (0);
  return (stone->nb);
}
