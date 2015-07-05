/*
** my_softwar.h for softwar in /home/clementcosson/C/SoftWar/cosson_c
**
** Made by COSSON Clement
** Login   <cosson_c@etna-alternance.net>
**
** Started on  Wed Mar 18 01:01:05 2015 COSSON Clement
** Last update Mon Mar 23 00:24:43 2015 COSSON Clement
*/
#ifndef __SOFTWAR_H__
#define __SOFTWAR_H__

#define ARGC_MIN 5
#define ARGC_MAX 10
#define PORT_MIN 1024
#define PORT_MAX 65535
#define SIZE_MAP_MIN 4
#define SIZE_MAP_MAX 16
#define SIZE_MAP_DEFAUT 10
#define CYCLE_MIN 100000
#define CYCLE_MAX 1000000
#define CYCLE_DEFAUT 500000
#define T_MAX_TABLE 250
#define CMD_IGN "Les commandes de plus de 250 sont ignorées\n"
#define CANT_NOT_CREATE_SOCK "Impossible de créer une socket"
#define CON_OK "Connection OK"
#define CON_KO "Erreur de connection"
#define BIN_NAME "./bin/soft-war-server"
#define VERBOSE_NAME "-v"
#define SIZE_NAME "--size"
#define LOG_NAME "--log"
#define CYCLE_NAME "--cycle"
#define PORT_NAME "--port"
#define CLIENT_ALIVE 0
#define CLIENT_DEAD 1
#define CLIENT_SLEEP_1 2
#define CLIENT_SLEEP_2 3

/*
**	-v (active le mode verbeux)
**	--size [nombre entier correspondant à la taille de la map]
**	--log [adresse absolue du log]
**	--fd_log [file director du fichier de log]
**	--cycle [nombre entier de microsecondes correspondant à un cycle]
**	--port [port du serveur]
*/
typedef			struct
{
  int			v;
  int			size;
  char			*log;
  int			fd_log;
  int			cycle;
  unsigned short	port;
}			t_args;
/*
**	--> empty  : 0 pas d'énergie sur la case, 1 energie sur la case
**	--> energy : 0 pas de client, 1 || 2 || 3 || 4 client sur la map
**	--> num_client : 0 pas de client, 1 || 2 || 3 || 4 client sur la map;
*/
typedef			struct
{
  int			empty;
  int			energy;
  int			num_client;
}			t_map;
/*
**	--> signature	: signature numérique du client
**	--> i		: coordonnées i dans la matrice
**	--> j		: coordonnées j dans la matrice ()
**	--> pivot	: lié a un énumération pour le sens du client FBLR
**	--> status	: OK, 1_TOUR (d'attente), 2_TOUR, MORT
*/
typedef			struct
{
  char			signature;
  int			i;
  int			j;
  enum position		pivot;
  int			status;
}			t_client;

enum position {left, forward, right, back};

/*
**	===================================================================
**	=============================== main.c ============================
**	===================================================================
*/
/*
**	free les pointeurs
*/
int     free_it_before_end(t_args *s_args, t_map *s_map);
/*
**	**	retourne NULL
**	affiche un message pour dire qu'il y a eu une erreur mémoire
*/
void    *return_memory_error_ptr();
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
**	Deuxieme fonction pour check_if_params_are_corrects
**	Permet de metre le code à la norme suivante
**	Norme Epitech, Version 0.42 bis, révisée pour l'ETNA
*/
int     check_if_params_are_corrects_bis(char *av_name, char *av_arg,
                                         t_args *s_as);

/*
**	initialise la structure
*/
void	init_args(t_args *s_as);

/*
**	met des paramètres par defaut si
**	ils ne sont pas renseigner dans l'appel du programme
*/
int     put_defaut_param(t_args *s_as);

/*
**	===================================================================
**	======================== main_functions_2.c =======================
**	===================================================================
*/
/*
**	regarde si le port renseigné est correct
**	check si le port est numérique et bien compris entre
**	PORT_MIN && PORT_MAX
*/
int     check_if_port_is_correct(char *port, t_args *s_as);
/*
**	regarde si la taile de la map est correct
*/
int     check_if_size_is_correct(char *size, t_args *s_as);
/*
**	regarde si le cycle est correct
*/
int     check_if_cycle_is_correct(char *cycle, t_args *s_as);
/*
**	regarde si c'est possible d'écrire dans le fichier de log
*/
int     check_if_log_is_correct(char *log_file, t_args *s_as);

/*
**	===================================================================
**	=================== print_error_launch_server_1.c =================
**	===================================================================
*/
/*
**	Si nb arg incorect
*/
int     print_error_arg(int ac);
/*
**	Si nom du binaire incorrect
*/
int     print_error_bin(char *str);
/*
**	Si un argument n'est pas compris dans la liste des args
*/
int     print_error_argv(char *str);

/*
**	===================================================================
**	=================== print_error_launch_server_2.c =================
**	===================================================================
*/
/*
**	affiche l'erreur au niveau de l'arg size
*/
int     print_error_size(char* str);
/*
**	affiche l'erreur au niveau de l'arg log
*/
int     print_error_log(char* str);
/*
**	affiche l'erreur au niveau de l'arg log
*/
int     print_error_cycle(char* str);
/*
**	affiche l'erreur au niveau de l'arg log
*/
int     print_error_port(char* str);
/*
**	retourne le parametre passé en argument
**	affiche un message pour dire qu'il y a eu une erreur mémoire
*/
int     return_memory_error(int error_code);
/*
**	===================================================================
**	========================== map_functions_1.c ======================
**	===================================================================
*/
/*
**	Fait l'allocation dynamique de la map
*/
t_map	*init_map(t_map *s_map, t_args *s_as);
/*
**	affiche la matrice
*/
void    display_map(t_map *s_map, t_args *s_as);
#endif
