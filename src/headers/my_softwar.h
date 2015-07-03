/*
** my_softwar.h for softwar in /home/clementcosson/C/SoftWar/cosson_c
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Wed Mar 18 01:01:05 2015 COSSON Clement
** Last update Wed Mar 18 04:46:50 2015 COSSON Clement
*/
#ifndef __SOFTWAR_H__
#define __SOFTWAR_H__

#define MAX_LEN_IP_V6 39
#define PORT_MIN 1024
#define PORT_MAX 65535
#define T_MAX_TABLE 250
#define CMD_IGN "Les commandes de plus de 250 sont ignorées\n"
#define IP_V6_NOT_IMPL "La connection en IP v6 n'est pas implémenté\n"
#define CANT_NOT_CREATE_SOCK "Impossible de créer une socket"
#define CON_OK "Connection OK"
#define CON_KO "Erreur de connection"

/*
**	--ip [adresse ip du serveur]
**	--port [port du serveur]
**	--cycle [nombre entier de microsecondes correspondant à un cycle]
**	-v (active le mode verbeux)
**	--log [adresse absolue du log]
**	--size [nombre entier correspondant à la taille de la map]
*/
typedef struct
{
  int			v_ip;
  char			ip[MAX_LEN_IP_V6];
  int			v;
  int			size;
  unsigned short	port;
  int			d_socket;
  char			*log;
  int			cycle;
}			t_args;

/*
**	===================================================================
**	======================== main_functions_1.c =======================
**	===================================================================
*/

/*
**	fonctions pour afficher un usage
*/
void	print_usage();

/*
**	fonctions de vérification des paramètres
**	retourne 1 si les arguments sont correct
**	0 dans le cas contraire
*/
int	check_if_params_are_corrects(int ac, char **av, t_args *s_as);

/*
**	fonction qui check quelle type d'ip lutilisateur semble utiliser
**	retourn 4 pour un V4, 6 pour une V6 et 0 si ni V4 ni V6
*/
int	check_if_look_ip(char *str,  t_args *s_as);

/*
**	fonction qui check que l'ip (v4 ou v6 est correct ou non)
*/
int	check_if_ip_is_correct(int version_ip, char *str, int i, int index);

/*
**	check si le port est numérique et bien compris entre
**	PORT_MIN && PORT_MAX
*/
int	check_if_port_is_correct(char *port);

/*
**	===================================================================
**	======================== main_functions_1.c =======================
**	===================================================================
*/

#endif
