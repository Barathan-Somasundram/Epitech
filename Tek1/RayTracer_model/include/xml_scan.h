/*
** xml_scan.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Wed May 29 17:15:51 2013 vincent colliot
** Last update Sun Jun  9 05:53:55 2013 vincent colliot
*/

#ifndef XML_SCAN_H_
# define XML_SCAN_H_

#include "token.h"
#include "fd.h"

typedef struct s_token_scan{
  char	*name;
  void  (*call)(void *, t_token*);
}		t_token_scan;

typedef struct s_scan{
  char	*div;
  void	(*call)(void *, FD, char *);
}		t_scan;

char	*xml_token(t_token **, char *, FLAG, FD);

	/*display scan call*/
void	add_lum(void *,FD, char *);
void	add_eye(void *,FD, char *);
void	add_object(void *,FD, char *);

	/*light scan call*/
void	light_pos(void *, t_token *);
void	light_color(void *, t_token *);
void	light_shading(void *, t_token *);

	/*eye scan call*/
void	eye_pos(void *, t_token *);
void	eye_focus(void *, t_token *);
void	eye_scale(void *, t_token *);
void	eye_shading(void *, t_token *);
void	eye_filter(void *, t_token *);

#endif
