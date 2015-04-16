/*
** struct.h for lem-in in /home/potier_g/prog_elem/potier_g
** 
** Made by potier_g
** Login   <potier_g@epitech.net>
** 
** Started on  Sat Apr 26 16:27:07 2014 potier_g
** Last update Sun May  4 22:08:35 2014 potier_g
*/

typedef struct		s_base t_base;
typedef struct		s_tube t_tube;
typedef struct		s_move t_move;
typedef struct		s_coor t_coor;

struct			s_coor
{
  int			*x;
  int			*y;
};

struct			s_base
{
  char			*name;
  int			x;
  int			y;
};

struct			s_tube
{
  char			*name1;
  char			*name2;
};

struct			s_move
{
  int			nbr_ant;
  t_coor		pos_act;
  t_coor		vect;
  int			*posx_act;
  int			*posy_act;
  char                  **prev_base;
  char			**nxt_base;
};

typedef struct		s_param
{
  int			nbr_ant;
  char			*name_start;
  int			size_base;
  int			size_tube;
  int			size_move;
  int			cam;
  int			camy;
  int			view;
  t_base		*base;
  t_tube		*tube;
  t_move		*move;
}			t_param;

char			*recup_line(char *file, int nb_line);
char			*recup_word(char *line, int nb_word);
int			cylinder_fdf(int *pos, double angle, int size);
double			recup_angle(int *loc);
int			aff_cylinder(t_param *param, int act);
int			sphere_fdf(int x, int y);
int			*init_posx(int size, t_move move, t_param *param, int s);
int			*init_posy(int size, t_move move, t_param *param, int s);
int			*calc_vect(t_coor start, t_coor end, int size, int s);
int			move_ant(t_move move, t_param *param);
int			my_start(t_param *param);
int			my_strlen(char *str);
void			*my_alloc(int size);
char			*my_malloc(int size);
char			*my_strcat(char *str, char *tmp);
char			*my_read();
char			*detect_start(char *file);
int			limit_x(t_base *base, int len, int sign);
int			limit_y(t_base *base, int len, int sign);
t_tube			*init_tube(char *file, int line_s, int line_e, t_param *param);
int			detect_nbr_ant(char *line);
char			*my_new(char *str);
char			**reinit(char **tab, int size);
int			init_move2(char *line, int pos, t_move *move, t_param *param);
t_move			*init_move(char *file, int line_s, int line_e, t_param *param);
int			init_move_ant(t_move *move, t_param *param, t_coor *end);
int			my_get_nbr(char *nb);
int			check_char(char *line, char c);
t_param			*init_file2(char *file, t_param *param, int line_s, int line_e);
t_param			*init_file(t_param *param);
char			*my_strdup(char *str);
int			my_strcmp(char *str1, char *str2);
t_base			*init_base(char *file, int line_s, int line_e, t_param *p);
int			pause();
int			event2(int sign, t_param *param);
int			event(t_param *param, t_move move);
int			detect_end(t_coor start, t_coor end, int size);
int			draw_ant(t_param *param, t_move move, int pos);
int			cam_sdl(t_param *param, t_move move);
int			cam_3perso(int pos, t_move move);
int			cam_1perso(int pos, t_move move);
int			cam_global(t_base *base, int len, int y);
int			aff_map(t_param *param, t_move move);
int			detect_char_null(char c);
