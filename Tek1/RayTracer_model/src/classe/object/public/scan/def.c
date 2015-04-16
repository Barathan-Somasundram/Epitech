/*
** def.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Tue Jun  4 23:57:08 2013 vincent colliot
** Last update Thu Jun  6 18:33:42 2013 vincent colliot
*/

#include <stdio.h>
#include <unistd.h>
#include "strings.h"
#include "object.h"
#include "string.h"

static void	def_error(char *s)
{
  (void)printf("in object def, error :%s not defined\n", s);
  exit(-1);
}

void	object_shining(void *o, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "shine", RESOLVE, 0)) == NULL)
    def_error("shining");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("shining");
  ((((CLASS_OBJECT*)o)->shine) = atof(s));
}

/*
 *gamma == transpa
 */
void	object_gamma(void *o, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "gamma", RESOLVE, 0)) == NULL)
    def_error(GAMMA);
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error(GAMMA);
  (((CLASS_OBJECT*)o)->gamma) = atof(s) - (int)atof(s);
  if ((s = xml_token(&token, "diffraction", RESOLVE, 0)) == NULL)
    def_error(GAMMA);
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error(GAMMA);
  if (((((CLASS_OBJECT*)o)->diffract) = atof(s) - (int)atof(s)) < 0)
    ((CLASS_OBJECT*)o)->diffract = -((CLASS_OBJECT*)o)->diffract;
}

/*
 *alpha == reverb
 */
void	object_alpha(void *o, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "alpha", RESOLVE, 0)) == NULL)
    def_error(ALPHA);
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error(ALPHA);
  (((CLASS_OBJECT*)o)->alpha) = atof(s) - (int)atof(s);
}
