/*
** lemipc.h for  in /home/somasu_b/rendu/PSU_2014_lemipc/includes
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Mon Mar  2 15:46:44 2015 SOMASUNDRAM Barathan
** Last update Sun Mar  8 18:29:16 2015 SOMASUNDRAM Barathan
*/

#ifndef LEMIPC_H_
# define LEMIPC_H_

#include <SDL/SDL.h>

# define CLEAR		"\033[H\033[2J"
# define WINX		800
# define WINY		800
# define MAPX		10
# define MAPY		10
# define PWD_SIZE	4096
# define SEM_KEY_ID     47564
# define SEM_NB		153
# define SEM_RIGHTS	0666
# define SHM_SIZE	(sizeof(int) * ((MAPX * MAPY) + 3))
# define SHM_KEY_ID	5486
# define SHM_RIGHTS	0666
# define PLAYERS	MAPX * MAPY + 1
# define PLAYERS_MAX	PLAYERS + 1
# define POSX(idx)	(idx / MAPY)
# define POSY(idx)	(idx % MAPY)
# define IDX(x, y)	(y * MAPX + x)

extern int*		g_map;
extern int		g_pos;
extern int		g_shm_id;
extern int		g_sem_id;
extern int*		g_nb_player;

int			my_perror(char*);
void			signal_manager(void);
void			putpixel(SDL_Surface*, int, int, Uint32);
int			print_line_hor(SDL_Surface*, int);
int			print_line_vert(SDL_Surface*, int);
int			print_player(SDL_Surface*, int, int,  Uint32 tab[9]);
int			pop_player(int);
float			calc_dist(int, int);
int			recup_target_player(int, int);
int			recup_my_target(int);
int			check_target(int, int, float*, int*);
int			recup_zone(int);
int			create_get_shm(int*);
int			*recup_mem(int, int);
void			delete_shm(int);
int			create_game(int, int);
int			join_game(int, int);
SDL_Surface		*init_screen(void);
void			*print_map(void*);
int			create_get_shm(int*);
void			delete_shm(int);
int			init_semaphore(int*);
int			semaphore_delete(void);
int			pop_player(int);
int			nb_enemy_stick(int, int);
int			move_player(int, int);
int			nb_enemy_map(int);

#endif /* !LEMIPC_H_ */
