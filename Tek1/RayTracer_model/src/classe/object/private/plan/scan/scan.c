/*
** scan.c<3> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 15:20:09 2013 vincent colliot
** Last update Wed Jun  5 04:03:30 2013 vincent colliot
*/

#include <stdio.h>
#include <unistd.h>
#include "strings.h"
#include "object.h"
#include "string.h"

static void	def_error(char *s)
{
  (void)printf("in plan def, error :%s not defined\n", s);
  exit(-1);
}

void    plan_focus(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "x", RESOLVE, 0)) == NULL)
    def_error("x");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("x");
  ((t_plan*)l)->focus.x = (atof(s) * M_PI) / 180.0;
  free(s);
  if ((s = xml_token(&token, "z", RESOLVE, 0)) == NULL)
    def_error("z");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("z");
  ((t_plan*)l)->focus.z = (atof(s) * M_PI) / 180.0;
  free(s);
  if ((s = xml_token(&token, "y", RESOLVE, 0)) == NULL)
    def_error("y");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("y");
  ((t_plan*)l)->focus.y = (atof(s) * M_PI) / 180.0;
  free(s);
  ((t_plan*)l)->focus = convert_focus(((t_plan*)l)->focus);
}

void	plan_high(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "D", RESOLVE, 0)) == NULL)
    def_error("high");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("high");
  (((t_plan*)l)->d) = atof(s);
}

void	plan_color(void *l, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "r", RESOLVE, 0)) == NULL)
    def_error("r");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("r");
  (((t_plan*)l)->color.rgb)[R] = atof(s);
  free(s);
  if ((s = xml_token(&token, "b", RESOLVE, 0)) == NULL)
    def_error("b");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("b");
  (((t_plan*)l)->color.rgb)[B] = atof(s);
  free(s);
  if ((s = xml_token(&token, "g", RESOLVE, 0)) == NULL)
    def_error("g");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("g");
  (((t_plan*)l)->color.rgb)[G] = atof(s);
  free(s);
}
