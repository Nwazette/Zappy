/*
** mod_dl_load.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	<fcntl.h>
#include	<dlfcn.h>

#include	"error.h"
#include	"module.h"

void		*mod_dl_load(char *name)
{
  int		ace;
  char		*plus;
  void		*handle;

  ace = 0;
  plus = NULL;
  if (!name)
    return (NULL);
  if ((ace = access(name, F_OK)) != -1 && \
      (handle = dlopen(name, RTLD_NOW)))
    return (handle);
  else
    print_warning((ace != -1 ? dlerror() : "module not found '.so' append."));
  if ((strcmp(&name[(strlen(name) - 3)], ".so") != 0) && \
      (plus = malloc((strlen(name) + 4) * sizeof(*name))) &&
      (plus = strcpy(plus, name)) && (plus = strcat(plus, ".so")) && \
      ((ace = access(plus, F_OK)) != -1))
    handle = dlopen(plus, RTLD_NOW);
  free(plus);
  if (ace == -1 || handle == (void*)-1)
    print_warning((ace != -1 ? dlerror() : "no module to load."));
  return (handle);
}

bool		mod_load(char *name)
{
  t_module	*(*get_module)(void);
  t_module	*module;
  void		*handle;

  module = NULL;
  if (!(handle = mod_dl_load(name)))
    return (false);
  if (!(get_module = dlsym(handle, "get_module")))
    return (print_error(dlerror()));
  if (!(module = get_module()))
    return (false);
  module->handle = handle;
  if (!module->handshaking && !(module->handshaking =
				dlsym(handle, "handshaking")))
    return (print_error(dlerror()));
  if (!module->disconnection && !(module->disconnection =
			   dlsym(handle, "disconnection")))
    print_warning(dlerror());
  if (!module->update && !(module->update = dlsym(handle, "update")))
    print_warning(dlerror());
  if (!module->timer && !(module->timer = dlsym(handle, "timer")))
    print_warning(dlerror());
  return (mod_register(module));
}

