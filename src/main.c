/*
** main.c for softwar in /home/clementcosson/C/SoftWar/cosson_c
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Tue Mar 17 17:26:56 2015 COSSON Clement
** Last update Wed Mar 18 09:44:33 2015 COSSON Clement
*/
#include <stdio.h>
#include <stdlib.h>
#include "./headers/list.h"
#include "./headers/my.h"
#include "./headers/my_softwar.h"

int	main(int argc, char *argv[])
{
  t_args	*s_args;

  if ((s_args = malloc(sizeof(*s_args))) == NULL)
    return (0);
  if (check_if_params_are_corrects(argc, argv, s_args))
    {
      my_putstr("Au boulot");
    }
  else
    print_usage();
  free(s_args);
  return (0);
}
