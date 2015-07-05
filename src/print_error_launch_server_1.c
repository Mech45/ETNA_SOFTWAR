/*
** print_error_launch_server.c for soft-war in /home/clementcosson/C/SoftWar/soft-war
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Sun Mar 22 15:26:12 2015 COSSON Clement
** Last update Sun Mar 22 17:02:29 2015 COSSON Clement
*/
#include "./headers/my_softwar.h"
#include "./headers/list.h"
#include "../lib/my/src/headers/my.h"

int	print_error_arg(int ac)
{
  my_printf("Nombre d'arguments incorrects\n");
  my_printf("ARG_MIN -> %d\n", ARGC_MIN);
  my_printf("ARG_MAX -> %d\n", ARGC_MAX);
  my_printf("Vous avez utilisé %d argument", ac);
  if (ac > 1)
    my_printf("s\n");
  else
    my_printf("\n");
  return (0);
}

int	print_error_bin(char *str)
{
  my_printf("Nom du binaire incorect\n");
  my_printf("BIN_NAME -> "BIN_NAME"\n");
  my_printf("%s != "BIN_NAME"\n", str);
  return (0);
}

int	print_error_argv(char *str)
{
  my_printf("Votre argument %s est incorrect\n", str);
  my_printf("Veuillez prendre exemple sur USAGE ci dessus\n");
  return (0);
}


