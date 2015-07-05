/*
** print_error_launch_server_2.c for soft-war in /home/clementcosson/C/SoftWar/soft-war
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Sun Mar 22 16:23:28 2015 COSSON Clement
** Last update Sun Mar 22 17:03:02 2015 COSSON Clement
*/
#include "./headers/my_softwar.h"
#include "./headers/list.h"
#include "../lib/my/src/headers/my.h"

int	print_error_size(char* str)
{
  my_printf("Le "SIZE_NAME" %s est incorrect\n", str);
  my_printf("SIZE_MIN -> %d\n", SIZE_MAP_MIN);
  my_printf("SIZE_MAX -> %d\n", SIZE_MAP_MAX);
  return (0);
}

int	print_error_log(char* str)
{
  my_printf("Le fichier de "LOG_NAME" \"%s\"est incorect\n", str);
  return (0);
}

int	print_error_cycle(char* str)
{
  my_printf("Le "CYCLE_NAME" %s est incorrect\n", str);
  my_printf("CYCLE_MIN -> %d\n", CYCLE_MIN);
  my_printf("CYCLE_MAX -> %d\n", CYCLE_MAX);
  return (0);
}

int	print_error_port(char* str)
{
  my_printf("Le "PORT_NAME" %s est incorrect\n", str);
  my_printf("PORT_MIN -> %d\n", PORT_MIN);
  my_printf("PORT_MAX -> %d\n", PORT_MAX);
  return (0);
}
