/*
** main_functions_2.c for softwar in /home/clementcosson/C/SoftWar/cosson_c
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Wed Mar 18 04:37:42 2015 COSSON Clement
** Last update Sun Mar 22 22:53:00 2015 COSSON Clement
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "./headers/my_softwar.h"
#include "./headers/list.h"
#include "../lib/my/src/headers/my.h"

int     check_if_port_is_correct(char *port, t_args *s_as)
{
  int   nbr;

  if (my_str_isnum(port))
    {
      nbr = my_getnbr(port);
      if (nbr >= PORT_MIN && nbr <= PORT_MAX)
        {
	  s_as->port = nbr;
	  return (nbr);
	}
    }
  return (0);
}

int	check_if_size_is_correct(char *size, t_args *s_as)
{
  int   nbr;

  if (my_str_isnum(size))
    {
      nbr = my_getnbr(size);
      if (nbr >= SIZE_MAP_MIN && nbr <= SIZE_MAP_MAX)
        {
	  s_as->size = nbr;
	  return (nbr);
	}
    }
  return (0);
}

int	check_if_cycle_is_correct(char *cycle, t_args *s_as)
{
  int	nbr;

  if (my_str_isnum(cycle))
    {
      nbr = my_getnbr(cycle);
      if (nbr >= CYCLE_MIN && nbr <= CYCLE_MAX)
	{
	  s_as->cycle = nbr;
	  return (nbr);
	}
    }
  return (0);
}

int	check_if_log_is_correct(char *log_file, t_args *s_as)
{
  s_as->log = my_strcpy(log_file);
  if (s_as->log == NULL)
    return (0);
  s_as->fd_log = open(s_as->log, O_WRONLY | O_CREAT, "0655");
  if (s_as->fd_log == -1)
    return (0);
  else
    return (1);
}

int	return_memory_error(int	error_code)
{
  my_printf("Erreur mémoire, la programme a du s'arreter\n");
  return (error_code);
}

