/*
** token.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Tue May 28 17:36:19 2013 vincent colliot
** Last update Fri May 31 22:05:55 2013 vincent colliot
*/

#ifndef TOKEN_H_
# define TOKEN_H_

# include "flag.h"
# include "fd.h"

typedef struct s_token{
  char	*name;
  char	*token;
  struct s_token *next;
}		t_token;

# define OPEN_COMMENT	"<!--"
# define END_COMMENT	"-->"

# define INIT		0b0001
# define RESOLVE	0b0010
# define END		0b0100
# define A_END		0b1000

char    *move_to_end_comment(char *, FD);

#endif
