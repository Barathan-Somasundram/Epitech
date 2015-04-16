/*
** string.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 27 21:27:30 2013 vincent colliot
** Last update Fri May 31 20:44:05 2013 vincent colliot
*/

#ifndef STRING_H_
# define STRING_H_

# include <stdlib.h>
# include <string.h>
# include "fd.h"
#include "bool.h"

# define MATCH(s, c)	(!strcmp(s, c))
# define NMATCH(s, c)	(!strncmp(s, c, strlen(s)))
# define IN(c, s)	(s[strilen(s, c)] != 0)
# define S_IN(c, s)     (s[strslen(s, c)] != 0)
# define O_IN(s, c)	((s)[strspn(s, c)] == 0)

	/* s_len */
size_t	strilen(const char *, char);
size_t  strslen(const char *, const char *);
size_t	sstrlen(const char *, const char *);

	/* s_match */
size_t	hempty(const char *);
BOOL	empty(const char *);

	/* s_alloc */
void	*my_strdup(const char *);
void	*my_strndup(const char *, size_t);

#endif
