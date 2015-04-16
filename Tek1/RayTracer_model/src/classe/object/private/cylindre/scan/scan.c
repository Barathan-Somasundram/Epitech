/*
** scan.c<2> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 15:17:18 2013 vincent colliot
** Last update Sun Jun  9 17:17:24 2013 vincent colliot
*/

#include <stdio.h>
#include <unistd.h>
#include "strings.h"
#include "object.h"
#include "string.h"

static void	def_error(char *s)
{
  (void)printf("in cylindre def, error :%s not defined\n", s);
  exit(-1);
}

void    cylindre_pos(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "x", RESOLVE, 0)) == NULL)
    def_error("x");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("x");
  ((t_cylindre*)l)->position.x = atof(s);
  free(s);
  if ((s = xml_token(&token, "z", RESOLVE, 0)) == NULL)
    def_error("z");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("z");
  ((t_cylindre*)l)->position.z = atof(s);
  free(s);
  if ((s = xml_token(&token, "y", RESOLVE, 0)) == NULL)
    def_error("y");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("y");
  ((t_cylindre*)l)->position.y = atof(s);
  free(s);
}

void    cylindre_focus(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "x", RESOLVE, 0)) == NULL)
    def_error("x");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("x");
  ((t_cylindre*)l)->focus.x = (N_X(atof(s + strspn(s, "-+"))) * M_PI) / 180;
  free(s);
  if ((s = xml_token(&token, "z", RESOLVE, 0)) == NULL)
    def_error("z");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("z");
  ((t_cylindre*)l)->focus.z = (N_Y(atof(s + strspn(s, "-+"))) * M_PI) / 180;
  free(s);
  if ((s = xml_token(&token, "y", RESOLVE, 0)) == NULL)
    def_error("y");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("y");
  ((t_cylindre*)l)->focus.y = (N_Y(atof(s + strspn(s, "-+"))) * M_PI) / 180;
  free(s);
  ((t_cylindre*)l)->focus = convert_norm(convert_focus(((t_cylindre*)l)->focus));
  ((t_cylindre*)l)->focus.y = NM(((t_cylindre*)l)->focus.y);
  ((t_cylindre*)l)->focus.x = NM(((t_cylindre*)l)->focus.x);
  ((t_cylindre*)l)->focus.z = NM(((t_cylindre*)l)->focus.z);
}

void	cylindre_rayon(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "R", RESOLVE, 0)) == NULL)
    def_error("rayon");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("rayon");
  (((t_cylindre*)l)->rayon) = atof(s);
}

void	cylindre_color(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "r", RESOLVE, 0)) == NULL)
    def_error("r");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("r");
  (((t_cylindre*)l)->color.rgb)[R] = atof(s);
  free(s);
  if ((s = xml_token(&token, "b", RESOLVE, 0)) == NULL)
    def_error("b");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("b");
  (((t_cylindre*)l)->color.rgb)[B] = atof(s);
  free(s);
  if ((s = xml_token(&token, "g", RESOLVE, 0)) == NULL)
    def_error("g");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("g");
  (((t_cylindre*)l)->color.rgb)[G] = atof(s);
  free(s);
}
