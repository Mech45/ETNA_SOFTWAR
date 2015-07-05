/*
** my_getnbr.c for my_getnbr in /Users/clementcosson/Piscine/C/Journee_02/cosson_c/my_getnbr
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Wed Oct 23 11:05:39 2013 COSSON Clement
** Last update Sun Mar 22 11:29:24 2015 COSSON Clement
*/

#include "./headers/my.h"

int	my_getnbr(char *str)
{
  int	int_out;
  int	sign;

  int_out = 0;
  sign = 1;
  if (*str == '-')
    {
      sign = -1;
      str++;
    }
  while  (my_strlen(str) > 0 && (*str >= 48 || *str <= 57))
    {
      int_out = int_out * 10 + ((int) * str) - 48;
      str++;
    }
  return (int_out * sign);
}

