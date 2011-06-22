
#include	<strings.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<errno.h>
#include	<stdio.h>

#include	"conf.h"
#include	"zopt.h"
#include	"map.h"
#include	"server_zappy.h"

static void	init_opt_default(t_zopt	*optab)
{
  bzero(optab, sizeof(*optab));
  optab->port = default_port;
  optab->nb_client = default_nb_client;
  optab->delay = default_delay;
  optab->time = default_time;
  optab->width = default_width;
  optab->height = default_height;
}

static bool	multiple(char *opts[], t_list **list)
{
  int		tmp;

  tmp = optind - 1;
  while ((tmp) && opts[tmp] && opts[tmp][0] != '-')
    if (!(put_in_list(list, strdup(opts[tmp++]))))
      return (false);
  return (true);
}

static bool	options(char opt, char *opts[], t_zopt *optab)
{
  if (opt == 't')
    optab->delay = strtoul(optarg, NULL, 0);
  else if (opt == 'c')
    optab->nb_client = strtoul(optarg, NULL, 0);
  else if (opt == 'p')
    optab->port = strtoul(optarg, NULL, 0);
  else if (opt == 'r')
    optab->time = strtoul(optarg, NULL, 0);
  else if (opt == 'w')
    optab->width = strtoul(optarg, NULL, 0);
  else if (opt == 'x')
    optab->width = strtoul(optarg, NULL, 0);
  else if (opt == 'h')
    optab->height = strtoul(optarg, NULL, 0);
  else if (opt == 'y')
    optab->height = strtoul(optarg, NULL, 0);
  else if (opt == 'n')
    multiple(opts, &optab->team);
  else if (opt == 'm')
    multiple(opts, &optab->module);
  else if (opt == '?')
    return (false);
  return (true);
}

static void	epure(t_zopt *optab)
{
  if (optab->time <= 0)
    optab->time = default_time;
  if (optab->delay <= 0)
    optab->delay = default_delay;
}

void	lol(void *data)
{
  printf("test: %s\n", (char*)data);
}

bool		init_opt(int ac, char *opt[], t_zopt *optab)
{
  char		option;

  init_opt_default(optab);
  while ((option = getopt(ac, opt, "c:p:t:r:w:h:x:y:n:m:")) != -1)
    if ((!options(option, opt, optab)))
      {
	fprintf(stderr, "Usage: %s bla bla bla\n", (opt ? opt[0] : "Zappy"));
	return (false);
      }
  epure(optab);
  printf("modules: %d\n", get_list_len(optab->module));
  dump_list(optab->module, lol);
  printf("teams: %d\n", get_list_len(optab->team));
  dump_list(optab->team, lol);
  return (true);
}
