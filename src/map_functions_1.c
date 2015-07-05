/*
** map_functions_1.c for soft-ware in /home/clementcosson/C/SoftWar/soft-war
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Sun Mar 22 20:24:29 2015 COSSON Clement
** Last update Mon Mar 23 01:04:32 2015 COSSON Clement
*/
#include <stdio.h>
#include <stdlib.h>
#include "./headers/my_softwar.h"
#include "./headers/list.h"
#include "../lib/my/src/headers/my.h"

t_map	*init_map(t_map *s_map, t_args *s_as)
{
  int	i;
  int	j;

  if ((s_map = malloc(s_as->size * s_as->size * sizeof(*s_map))) == NULL)
    return ((t_map *) return_memory_error_ptr());
  for (j = 0; j < s_as->size; j++)
    for (i = 0; i < s_as->size; i++)
      {
	s_map[i + s_as->size * j].empty = 1;
	s_map[i + s_as->size * j].energy = 0;
	s_map[i + s_as->size * j].num_client = 0;
      }
  return (s_map);
}

void	display_map(t_map *s_map, t_args *s_as)
{
  int	i;
  int	j;

  for (i = 0; i < s_as->size; i++)
    for (j = 0; j < s_as->size; j++)
      {
	if (s_map[i * s_as->size + j].empty)
	  my_printf(" _ ");
	else if (s_map[i * s_as->size + j].energy)
	  my_printf(" E ");
	else
	  my_printf(" %d ", s_map[i * s_as->size + j].num_client);
	if ((j + 1) == s_as->size)
	  my_printf("\n");
      }
}

int	put_client_in_da_matrice(t_client *client, t_map *s_map, t_args *s_as)
{
  if (s_map[0].empty)
    {
      put_client_in_da_matrice_bis();
      s_map[0].empty = 0;
      client->i = 0;
      client->j = 0;
    }
  else if (s_map[s_as->size - 1].empty)
    {
      s_map[s_as->size - 1].empty = 0;
      client->i = 0;
      client->j = s_as->size - 1;
    }
  else if (s_map[s_as->size * s_as->size - s_as->size].empty)
    {
      s_map[s_as->size * s_as->size - s_as->size] = 0;
      client->i = s_as->size - 1;
      client->j = 0;
    }
  else if (s_map[s_as->size * s_as->size - 1].empty)
    {
      s_map[s_as->size * s_as->size - 1];
      client->i = s_as->size - 1;
      client->j = s_as->size - 1;
    }
  else
    return (0);
  return (1);
}

void	put_client_in_da_matrice_bis(t_client *client, t_map *s_map,
				     int max, int i, int j)
{
  client->i = i;
  client->j = j;
  if (i == 0 && j == 0)
      s_map[0].empty = 0;
  else if (i == 0 && j == (max - 1))
      s_map[max - 1].empty = 0;
  else if (i == (max - 1) && j == 0)
      s_map[max * max - max].empty = 0;
  else
      s_map[max * max - 1].empty = 0;
}

