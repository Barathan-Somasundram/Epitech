/*
** def2.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sun Jun  9 05:41:37 2013 vincent colliot
** Last update Sun Jun  9 16:00:44 2013 quentin cloarec
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

void	eye_filter(void *l, t_token *token)
{
  char	*s;

  s = xml_token(&token, "type", RESOLVE, 0);
  if (MATCH(s, "grey"))
    ((CLASS_EYE*)l)->filter = 1;
  else if (MATCH(s, "sepia"))
    ((CLASS_EYE*)l)->filter = 2;
  else if (MATCH(s, "negatif"))
    ((CLASS_EYE*)l)->filter = 3;
  else if (MATCH(s, "black and white"))
    ((CLASS_EYE*)l)->filter = 4;
  else if (MATCH(s, "red"))
    ((CLASS_EYE*)l)->filter = 5;
  else if (MATCH(s, "blue"))
    ((CLASS_EYE*)l)->filter = 6;
  else if (MATCH(s, "green"))
    ((CLASS_EYE*)l)->filter = 7;
  else
    def_error("filter's type");
}
