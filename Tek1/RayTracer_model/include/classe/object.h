/*
** object.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt/src/classe/display
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu May 16 22:11:47 2013 vincent colliot
** Last update Sun Jun  9 17:17:45 2013 vincent colliot
*/

#ifndef OBJECT_H_
# define OBJECT_H_

# include "u_color.h"
# include "xml_scan.h"
# include "dim.h"
# include "methode_name.h"
# include "methode_object.h"
# include "collide.h"
# include "deform.h"
# include "bool.h"
# include "limit.h"

# define NM(n) (((n) < 0) ? (-n) : (n))
# define N_Y(n) (n)
# define N_X(n) (n)


struct s_object;
struct s_display;
#include "methode_cylindre.h"
typedef struct s_cylindre{
  /* public */
  void	*next;
  t_3d	(*collide)(void *, t_3d, t_3d, t_collide *);
  t_3d	(*normal)(void *, t_3d, t_collide*);
  t_color (*get_color)(struct s_display *, void *, t_collide, t_3d[2]);
  void	(*rotation)(void *, FLAG);
  void	(*translation)(void *, FLAG);
  void	*(*copy)(void *);
  FLAG perturb;
  double alpha;
  double gamma;
  double diffract;
  double shine;
  /* private */
  t_limit	limit[6];
  FLAG		to_deform;
  t_deform	deform[3];
  t_token_scan *obj_scan;
  t_token_scan *scan;
  t_color	color;
  BOOL		selected;
  /*int	*permtab_perlin*/
  t_3d	position;
  t_3d	focus;
  double rayon;
}		t_cylindre;

#include "methode_cone.h"
typedef struct s_cone{
  /* public */
  void	*next;
  t_3d	(*collide)(void *, t_3d, t_3d, t_collide *);
  t_3d	(*normal)(void *, t_3d, t_collide*);
  t_color (*get_color)(struct s_display *, void *, t_collide, t_3d[2]);
  void	(*rotation)(void *, FLAG);
  void	(*translation)(void *, FLAG);
  void	*(*copy)(void *);
  FLAG perturb;
  double alpha;
  double gamma;
  double diffract;
  double shine;
  /* private */
  t_limit	limit[6];
  FLAG		to_deform;
  t_deform	deform[3];
  t_token_scan *obj_scan;
  t_token_scan *scan;
  t_color	color;
  BOOL		selected;
  /*int	*permtab_perlin*/
  t_3d	position;
  t_3d	focus;
  double angle;
}		t_cone;

#include "methode_sphere.h"
typedef struct s_sphere{
  /* public */
  void	*next;
  t_3d	(*collide)(void *, t_3d, t_3d, t_collide *);
  t_3d	(*normal)(void *, t_3d, t_collide*);
  t_color (*get_color)(struct s_display *, void *, t_collide, t_3d[2]);
  void	(*rotation)(void *, FLAG);
  void	(*translation)(void *, FLAG);
  void	*(*copy)(void *);
  FLAG perturb;
  double alpha;
  double gamma;
  double diffract;
  double shine;
  /* private */
  t_limit	limit[6];
  FLAG		to_deform;
  t_deform	deform[3];
  t_token_scan *obj_scan;
  t_token_scan *scan;
  t_color	color;
  BOOL		selected;
  /*int	*permtab_perlin*/
  t_3d	position;
  double rayon;
}		t_sphere;

# include "methode_plan.h"
typedef struct s_plan{
  /* public */
  void	*next;
  t_3d	(*collide)(void *, t_3d, t_3d, t_collide *);
  t_3d	(*normal)(void *, t_3d, t_collide*);
  t_color (*get_color)(struct s_display *, void *, t_collide, t_3d[2]);
  void	(*rotation)(void *, FLAG);
  void	(*translation)(void *, FLAG);
  void	*(*copy)(void *);
  FLAG perturb;
  double alpha;
  double gamma;
  double diffract;
  double shine;
  /* private */
  t_limit	limit[6];
  FLAG		to_deform;
  t_deform	deform[3];
  t_token_scan *obj_scan;
  t_token_scan *scan;
  t_color	color;
  BOOL		selected;
  /*int	*permtab_perlin*/
  t_3d	focus;
  float d;
}		t_plan;

typedef struct s_object{
  /* public */
  struct s_object	*next;
  t_3d	(*collide)(void *, t_3d, t_3d, t_collide *);
  t_3d	(*normal)(void *, t_3d, t_collide*);
  t_color (*get_color)(struct s_display *, void *, t_collide, t_3d[2]);
  void	(*rotation)(void *, FLAG);
  void	(*translation)(void *, FLAG);
  void	*(*copy)(void *);
  FLAG perturb;
  double alpha;
  double gamma;
  double diffract;
  double shine;
  /* private */
  t_limit	limit[6];
  FLAG		to_deform;
  t_deform	deform[3];
  t_token_scan *obj_scan;
  t_token_scan *scan;
  t_color	color;
  BOOL		selected;
  /*int	*permtab_perlin*/
}		t_object;

# define CLASS_OBJECT t_object

	/* objects defines */
void	objects_init(CLASS_OBJECT**, void*, char*, FD);
void    sphere_init(void *, t_token *);
void    plan_init(void *, t_token *);
void    cone_init(void *, t_token *);
void    cylindre_init(void *, t_token *);

#endif
