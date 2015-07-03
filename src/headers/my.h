/*
** my_list.h for my_list in /Users/clementcosson/Piscine/C/Journee_09/cosson_c/my_list
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Fri Nov  1 09:46:49 2013 COSSON Clement
** Last update Tue Mar 17 17:45:51 2015 COSSON Clement
*/
#ifndef __MY_H__
# define __MY_H__
char	my_getchar();
int	my_getnbr(char *str);
void	my_putchar(char c);
int	my_putstr(char *str);
char	*my_revstr(char *str);
int	my_strcmp(char *s1, char *s2);
char	*my_strcpy(char *dest, char *src);
int	my_str_isnum(char *str);
int	my_strlen(char *str);
#endif
