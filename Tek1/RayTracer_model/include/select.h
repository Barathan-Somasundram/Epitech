/*
** select.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Wed Jun  5 14:05:50 2013 vincent colliot
** Last update Sun Jun  9 16:35:23 2013 vincent colliot
*/

#ifndef SELECT_H_
# define SELECT_H_

# define OSELECT 1
# define LSELECT 2
# define VSELECT 3

/*---- KEY MAPPING ----*/
# define FIXED	102
# define MSCALE 65451
# define LSCALE 65453
# define KCOPY	99
/*---*/
# define Rmore	65430
# define Gmore	65437
# define Bmore	65432
# define Rless	65436
# define Gless	65433
# define Bless	65435
/*---*/
# define LIGHT	65362
# define VIEW	65364
# define NLIGHT	65361
# define PLIGHT	65363
/*---*/
# define Rup	97
# define Rdown	101
# define Rleft	113
# define Rright	100
# define Rfront	115
# define Rback	122
/*---*/
# define Kup	109
# define Kdown	107
# define Kleft	111
# define Kright	108
# define Kfront	105
# define Kback	112
/*--- Associate mapping ---*/
# define MRmore		0b000001
# define MGmore		0b000010
# define MBmore		0b000100
# define MRless		0b001000
# define MGless		0b010000
# define MBless		0b100000
/*---*/
# define MKup		0b000001
# define MKdown		0b001000
# define MKleft		0b010000
# define MKright	0b000010
# define MKfront	0b100000
# define MKback		0b000100
/*---*/
# define MRup		0b000001
# define MRdown		0b001000
# define MRleft		0b010000
# define MRright	0b000010
# define MRfront	0b100000
# define MRback		0b000100

typedef struct s_select{
  /* key */
  FLAG	rgb;
  FLAG	key_m;
  FLAG	key_r;
  BOOL	fixed;
  /* touch */
  FLAG		type;
  t_object	*oselect;
  t_light	*lselect;
  t_screen	*screen;
  CLASS_DISPLAY	*d;
  /* booleene de changement*/
  BOOL		exit;
  BOOL		changed;
}		t_select;

# define EXIT 65307

# define TMOVE 0.5
# define RMOVE 0.05
# define CMOVE 5

# define MIN_MOD 1.0
# define MAX_MOD 8.0

int	nfn(t_screen*);
int	get(int, int, int, t_select*);
int	keypress(int, t_select*);
int	keyrelease(int, t_select*);
int	__stay_alert(t_select*);
int     mlx_flush_event(void *mlx_ptr);

#endif
