/*
** main.c for softwar in /home/clementcosson/C/SoftWar/cosson_c
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Tue Mar 17 17:26:56 2015 COSSON Clement
** Last update Sun Mar 22 17:38:41 2015 COSSON Clement
*/
#include <stdio.h>
#include <stdlib.h>
#include "./headers/list.h"
#include "../lib/my/src/headers/my.h"
#include "./headers/my_softwar.h"

int	main(int argc, char *argv[])
{
  t_args	*s_args;

  if ((s_args = malloc(sizeof(*s_args))) == NULL)
    return (0);
  init_args(s_args);
  if (check_if_params_are_corrects(argc, argv, s_args))
    {
      printf("Au boulot \n");
      printf("s_args->v == %d\n", s_args->v);
      printf("s_args->size == %d\n", s_args->size);
      printf("s_args->log == %s\n", s_args->log);
      printf("s_args->fd_log == %d\n", s_args->fd_log);
      printf("s_args->cycle == %d\n", s_args->cycle);
      printf("s_args->port == %d\n", s_args->port);
    }
  else
    print_usage();
  free(s_args);
  return (0);
}
