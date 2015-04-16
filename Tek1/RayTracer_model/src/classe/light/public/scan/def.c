/*
** def.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt/src/classe/display/public/scan
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 27 17:28:16 2013 vincent colliot
** Last update Wed Jun  5 21:35:56 2013 vincent colliot
*/

#include <stdio.h>
#include <unistd.h>
#include "strings.h"
#include "light.h"
#include "string.h"

static void	def_error(char *s)
{
  (void)printf("in light def, error :%s not defined\n", s);
  exit(-1);
}

void    light_pos(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "x", RESOLVE, 0)) == NULL)
    def_error("x");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("x");
  ((CLASS_LIGHT*)l)->position.x = atof(s);
  free(s);
  if ((s = xml_token(&token, "z", RESOLVE, 0)) == NULL)
    def_error("z");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("z");
  ((CLASS_LIGHT*)l)->position.z = atof(s);
  free(s);
  if ((s = xml_token(&token, "y", RESOLVE, 0)) == NULL)
    def_error("y");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("y");
  ((CLASS_LIGHT*)l)->position.y = atof(s);
  free(s);
}

void	light_color(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "r", RESOLVE, 0)) == NULL)
    def_error("r");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("r");
  (((CLASS_LIGHT*)l)->color.rgb)[R] = atof(s);
  free(s);
  if ((s = xml_token(&token, "b", RESOLVE, 0)) == NULL)
    def_error("b");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("b");
  (((CLASS_LIGHT*)l)->color.rgb)[B] = atof(s);
  free(s);
  if ((s = xml_token(&token, "g", RESOLVE, 0)) == NULL)
    def_error("g");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("g");
  (((CLASS_LIGHT*)l)->color.rgb)[G] = atof(s);
  free(s);
}

void	light_shading(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "scale", RESOLVE, 0)) == NULL)
    def_error("scale");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("scale");
  if (!((((t_light*)l)->render.scale) = atof(s)))
    (((t_light*)l)->render.scale) = -1;
  if ((s = xml_token(&token, "n", RESOLVE, 0)) == NULL)
    def_error("n");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("n");
  if (!((((t_light*)l)->render.n) = atof(s)))
    (((t_light*)l)->render.n) = -1;
}
