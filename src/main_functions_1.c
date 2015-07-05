/*
** main_functions.c for softwar in /home/clementcosson/C/SoftWar/cosson_c
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Wed Mar 18 01:11:19 2015 COSSON Clement
** Last update Sun Mar 22 17:37:15 2015 COSSON Clement
*/
#include <stdio.h>
#include <stdlib.h>
#include "./headers/my_softwar.h"
#include "./headers/list.h"
#include "../lib/my/src/headers/my.h"

void	print_usage()
{
  my_putstr("USAGE : "BIN_NAME" ["VERBOSE_NAME"] ["SIZE_NAME" map_size]");
  my_putstr(" "LOG_NAME" absolut_path_log_file ["CYCLE_NAME" nb_cycle] ");
  my_putstr(""PORT_NAME" port_number\n");
  my_putstr("Exemple : "BIN_NAME" "VERBOSE_NAME" "SIZE_NAME" 8");
  my_putstr(" "LOG_NAME" /tmp/soft_war.log "CYCLE_NAME" 1000000 ");
  my_putstr("--port 4242\n");
}

void	init_args(t_args *s_as)
{
  s_as->v = 0;
  s_as->size = 0;
  s_as->log = NULL;
  s_as->cycle = 0;
  s_as->port = 0;
}

int	check_if_params_are_corrects(int ac, char **av, t_args *s_as)
{
  int	i;

  i = 0;
  if (!(ac >= ARGC_MIN && ac <= ARGC_MAX))
    return (print_error_arg(ac));
  for (i = 0; i < ac; i++)
    {
      if (i == 0 && (my_strcmp(av[i], BIN_NAME) != 0))
	return (print_error_bin(av[i]));
      else if (i > 0 && my_strcmp(av[i], VERBOSE_NAME) != 0 &&
		my_strcmp(av[i], SIZE_NAME) != 0 &&
		my_strcmp(av[i], LOG_NAME) != 0 &&
		my_strcmp(av[i], CYCLE_NAME) != 0 &&
		my_strcmp(av[i], PORT_NAME) != 0)
	return (print_error_argv(av[i]));
      else if (my_strcmp(av[i], VERBOSE_NAME) == 0)
	s_as->v = 1;
      else if (i > 0)
	{
	  if (!check_if_params_are_corrects_bis(av[i], av[i + 1], s_as))
	    return (0);
	  i++;
	}
    }
  return (put_defaut_param(s_as)) ? (1) : (0);
}

int	check_if_params_are_corrects_bis(char *av_name, char *av_arg,
					 t_args *s_as)
{
  if (my_strcmp(av_name, SIZE_NAME) == 0)
    {
      if (!check_if_size_is_correct(av_arg, s_as))
	return (print_error_size(av_arg));
    }
  else if (my_strcmp(av_name, LOG_NAME) == 0)
    {
      if (!check_if_log_is_correct(av_arg, s_as))
	return (print_error_log(av_arg));
    }
  else if (my_strcmp(av_name, CYCLE_NAME) == 0)
    {
      if (!check_if_cycle_is_correct(av_arg, s_as))
	return (print_error_cycle(av_arg));
    }
  else if (my_strcmp(av_name, PORT_NAME) == 0)
    {
      if (!check_if_port_is_correct(av_arg, s_as))
	return (print_error_port(av_arg));
    }
  return (1);
}

int	put_defaut_param(t_args *s_as)
{
  if (s_as->size == 0)
    s_as->size = SIZE_MAP_DEFAUT;
  if (s_as->cycle == 0)
    s_as->cycle = CYCLE_DEFAUT;
  if (s_as->log == NULL)
    {
      my_printf("Vous devez renseigner l'argument "LOG_NAME"\n");
      my_printf("voir l'USAGE ci dessous");
      return (0);
    }
  if (s_as->port == 0)
    {
      my_printf("Vous devez renseigner l'argument "PORT_NAME"\n");
      my_printf("voir l'USAGE ci dessous");
      return (0);
    }
  return (1);
}

