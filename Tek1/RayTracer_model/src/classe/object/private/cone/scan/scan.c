/*
** scan.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 15:12:00 2013 vincent colliot
** Last update Sun Jun  9 17:22:29 2013 vincent colliot
*/

#include <stdio.h>
#include <unistd.h>
#include "strings.h"
#include "object.h"
#include "string.h"

# define NM(n) (((n) < 0) ? (-n) : (n))

static void	def_error(char *s)
{
  (void)printf("in cone def, error :%s not defined\n", s);
  exit(-1);
}

void    cone_pos(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "x", RESOLVE, 0)) == NULL)
    def_error("x");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("x");
  ((t_cone*)l)->position.x = atof(s);
  free(s);
  if ((s = xml_token(&token, "z", RESOLVE, 0)) == NULL)
    def_error("z");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("z");
  ((t_cone*)l)->position.z = atof(s);
  free(s);
  if ((s = xml_token(&token, "y", RESOLVE, 0)) == NULL)
    def_error("y");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("y");
  ((t_cone*)l)->position.y = atof(s);
  free(s);
  ((t_cone*)l)->focus = convert_norm(convert_focus(((t_cone*)l)->focus));
}

void    cone_focus(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "x", RESOLVE, 0)) == NULL)
    def_error("x");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("x");
  ((t_cone*)l)->focus.x = (N_X(atof(s + strspn(s, "-+"))) * M_PI) / 180;
  free(s);
  if ((s = xml_token(&token, "z", RESOLVE, 0)) == NULL)
    def_error("z");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("z");
  ((t_cone*)l)->focus.z = (N_Y(atof(s + strspn(s, "-+"))) * M_PI) / 180;
  free(s);
  if ((s = xml_token(&token, "y", RESOLVE, 0)) == NULL)
    def_error("y");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("y");
  ((t_cone*)l)->focus.y = (N_Y(atof(s + strspn(s, "-+"))) * M_PI) / 180;
  free(s);
  ((t_cone*)l)->focus = convert_norm(convert_focus(((t_cone*)l)->focus));
  ((t_cone*)l)->focus.y = NM(((t_cone*)l)->focus.y);
  ((t_cone*)l)->focus.x = NM(((t_cone*)l)->focus.x);
  ((t_cone*)l)->focus.z = NM(((t_cone*)l)->focus.z);
}

void	cone_angle(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "angle", RESOLVE, 0)) == NULL)
    def_error("angle");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("angle");
  (((t_cone*)l)->angle) = (atof(s) * M_PI) / 180;
  free(s);
}

void	cone_color(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "r", RESOLVE, 0)) == NULL)
    def_error("r");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("r");
  (((t_cone*)l)->color.rgb)[R] = atof(s);
  free(s);
  if ((s = xml_token(&token, "b", RESOLVE, 0)) == NULL)
    def_error("b");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("b");
  (((t_cone*)l)->color.rgb)[B] = atof(s);
  free(s);
  if ((s = xml_token(&token, "g", RESOLVE, 0)) == NULL)
    def_error("g");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("g");
  (((t_cone*)l)->color.rgb)[G] = atof(s);
  free(s);
}
