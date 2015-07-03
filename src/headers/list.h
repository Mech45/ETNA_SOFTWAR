/*
** list.h for my_minishell in /home/clementcosson/C/Minishell/cosson_c
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Fri Mar 13 19:58:08 2015 COSSON Clement
** Last update Tue Mar 17 17:44:21 2015 COSSON Clement
*/
#ifndef __LIST_H__
#define __LIST_H__

typedef struct		s_list_char
{
  char			c;
  struct s_list_char	*next;
}			t_list_char;

typedef struct		s_list_string
{
  char			*str;
  struct s_list_string	*next;
}			t_list_string;

typedef struct		s_list_path
{
  char			*name;
  char			*path;
  struct s_list_path	*next;
}			t_list_path;
/*
**      Créer une des liste chaines
*/
struct  s_list_char	*create_list_char(t_list_char *ptr);
struct  s_list_string	*create_list_string(t_list_string *ptr);
struct	s_list_path	*create_list_path(t_list_path *ptr);

/*
**      Suppression d'une liste
**      delete_list_* supprime toute une liste
**      delete_type supprime le premier element de la liste chaine
*/
struct	s_list_char	*delete_list_char(t_list_char *ptr);
struct	s_list_char	*delete_char(t_list_char *ptr);
struct	s_list_string	*delete_list_string(t_list_string *ptr);
struct	s_list_string	*delete_string(t_list_string *ptr);
struct	s_list_path	*delete_list_path(t_list_path *ptr);
struct	s_list_path	*delete_path(t_list_path *ptr);
/*
**      Ajoute une valeur dans une liste chainée
*/
struct	s_list_char	*add_char(t_list_char *ptr, char val);
struct	s_list_string	*add_string(t_list_string *ptr, char *str);
struct	s_list_path	*add_path(t_list_path *ptr, char *name, char *path);
/*
**	fonction annexe a add_path
*/
char			*concat_path_and_name(char *buf, char *name,
					      char *path);
/*
**	retourne le nombre d'élement que l'on peut trouver dans
**	une liste chainée char
*/
int			nb_elem_list_char(t_list_char *ptr);
/*
**	copie la liste chainé dans un tableau précédemment alloué
*/
void			cp_list_to_table(t_list_char *ptr, char *table);
#endif
