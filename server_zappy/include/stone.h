
#ifndef		STONE_H_
# define	STONE_H_

#include "ztypes.h"

typedef		enum
  {
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    NONE
  }		e_stone;

typedef		struct
{
  e_stone	type;
  uint		nb;
}		t_stone;

#endif		/* !STONE_H_ */
