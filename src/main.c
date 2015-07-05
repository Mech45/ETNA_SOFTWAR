/*
** main.c for softwar in /home/clementcosson/C/SoftWar/cosson_c
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Tue Mar 17 17:26:56 2015 COSSON Clement
** Last update Sun Mar 22 23:58:09 2015 COSSON Clement
*/
#include <stdio.h>
#include <stdlib.h>
#include "./headers/list.h"
#include "../lib/my/src/headers/my.h"
#include "./headers/my_softwar.h"

int		main(int argc, char *argv[])
{
  t_args	*s_args;
  t_map		*s_map;

  s_map = NULL;
  s_args = NULL;
  if ((s_args = malloc(sizeof(*s_args))) == NULL)
    return (return_memory_error(0));
  init_args(s_args);
  if (check_if_params_are_corrects(argc, argv, s_args))
    {
      if ((s_map = init_map(s_map, s_args)) == NULL)
	return (0);
      display_map(s_map, s_args);
    }
  else
    print_usage();
  return (free_it_before_end(s_args, s_map));
}

int	free_it_before_end(t_args *s_args, t_map *s_map)
{
  free(s_args->log);
  free(s_args);
  free(s_map);
  return (0);
}

void	*return_memory_error_ptr()
{
  my_printf("Erreur mémoire, la programme a du s'arreter\n");
  return (NULL);
}

