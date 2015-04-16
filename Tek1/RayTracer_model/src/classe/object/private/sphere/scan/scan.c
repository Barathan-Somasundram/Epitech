/*
** scan.c<4> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 15:21:14 2013 vincent colliot
** Last update Fri May 31 20:36:55 2013 vincent colliot
*/

#include <stdio.h>
#include <unistd.h>
#include "strings.h"
#include "object.h"
#include "string.h"

static void	def_error(char *s)
{
  (void)printf("in sphere def, error :%s not defined\n", s);
  exit(-1);
}

void    sphere_pos(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "x", RESOLVE, 0)) == NULL)
    def_error("x");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("x");
  ((t_sphere*)l)->position.x = atof(s);
  free(s);
  if ((s = xml_token(&token, "z", RESOLVE, 0)) == NULL)
    def_error("z");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("z");
  ((t_sphere*)l)->position.z = atof(s);
  free(s);
  if ((s = xml_token(&token, "y", RESOLVE, 0)) == NULL)
    def_error("y");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("y");
  ((t_sphere*)l)->position.y = atof(s);
  free(s);
}

void	sphere_rayon(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "R", RESOLVE, 0)) == NULL)
    def_error("rayon");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("rayon");
  (((t_sphere*)l)->rayon) = atof(s);
}

void	sphere_color(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "r", RESOLVE, 0)) == NULL)
    def_error("r");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("r");
  (((t_sphere*)l)->color.rgb)[R] = atof(s);
  free(s);
  if ((s = xml_token(&token, "b", RESOLVE, 0)) == NULL)
    def_error("b");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("b");
  (((t_sphere*)l)->color.rgb)[B] = atof(s);
  free(s);
  if ((s = xml_token(&token, "g", RESOLVE, 0)) == NULL)
    def_error("g");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("g");
  (((t_sphere*)l)->color.rgb)[G] = atof(s);
  free(s);
}
