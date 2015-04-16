/*
** def.c<2> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 02:39:32 2013 vincent colliot
** Last update Sun Jun  9 05:42:42 2013 vincent colliot
*/

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include "strings.h"
#include "eye.h"
#include "string.h"

static void	def_error(char *s)
{
  (void)printf("in eye def, error :%s not defined\n", s);
  exit(-1);
}

void    eye_pos(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "x", RESOLVE, 0)) == NULL)
    def_error("x");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("x");
  ((CLASS_EYE*)l)->position.x = atof(s);
  free(s);
  if ((s = xml_token(&token, "z", RESOLVE, 0)) == NULL)
    def_error("z");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("z");
  ((CLASS_EYE*)l)->position.z = atof(s);
  free(s);
  if ((s = xml_token(&token, "y", RESOLVE, 0)) == NULL)
    def_error("y");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("y");
  ((CLASS_EYE*)l)->position.y = atof(s);
  free(s);
}

void    eye_focus(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "x", RESOLVE, 0)) == NULL)
    def_error("x");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("x");
  ((CLASS_EYE*)l)->focus.x = (atof(s) * M_PI) / 180;
  free(s);
  if ((s = xml_token(&token, "z", RESOLVE, 0)) == NULL)
    def_error("z");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("z");
  ((CLASS_EYE*)l)->focus.z = (atof(s) * M_PI) / 180;
  free(s);
  if ((s = xml_token(&token, "y", RESOLVE, 0)) == NULL)
    def_error("y");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("y");
  ((CLASS_EYE*)l)->focus.y = (atof(s) * M_PI) / 180;
  free(s);
}

void	eye_scale(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "scale", RESOLVE, 0)) == NULL)
    def_error("scale");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("scale");
  if (!((((t_eye*)l)->scale) = atof(s)))
    (((t_eye*)l)->scale) = 1;
  if (((t_eye*)l)->scale < 0)
    ((t_eye*)l)->scale = -((t_eye*)l)->scale;
}

void	eye_shading(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "scale", RESOLVE, 0)) == NULL)
    def_error("scale");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("scale");
  if (!((((t_eye*)l)->render.scale) = atof(s)))
    (((t_eye*)l)->render.scale) = -1;
  if ((s = xml_token(&token, "n", RESOLVE, 0)) == NULL)
    def_error("n");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("n");
  if (!((((t_eye*)l)->render.n) = atof(s)))
    (((t_eye*)l)->render.n) = -1;
}
