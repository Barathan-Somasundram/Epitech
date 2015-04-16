/*
** s_token.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Tue May 28 00:19:33 2013 vincent colliot
** Last update Fri May 31 22:08:45 2013 vincent colliot
*/

#include "strings.h"
#include "token.h"
#include "xmalloc.h"

static t_token	*tokenize(char *s, FD xml, t_token *prev, char *end)
{
  t_token	*link;

  if (NMATCH(end, s += hempty(s)))
    {
      s += strlen(end);
      while (s && NMATCH(OPEN_COMMENT, s += hempty(s)))
	s = move_to_end_comment(s, xml);
      return (prev);
    }
  while (s && NMATCH(OPEN_COMMENT, s += hempty(s)))
    s = move_to_end_comment(s, xml);
  s += hempty(s);
  link = xmalloc(sizeof(*link));
  s += strlen(link->name = my_strndup(s, sstrlen(s, " \t=")));
  link->next = NULL;
  if (prev)
    prev->next = link;
  if (!(strspn(s, " \t =") == strilen(s, '"')) || !IN('"', s))
    return (NULL);
  s += strilen(s, '"') + 1;
  if (!IN('"', s))
    return (NULL);
  link->token = my_strndup(s, strilen(s, '"'));
  if (tokenize(s + strlen(link->token) + 1, xml, link, end) == NULL)
    return (NULL);
  return (link);
}

static char	*token_ini(t_token **tok, char *s, FD xml, char *end)
{
  char	*name;

  while (s && NMATCH(OPEN_COMMENT, s += hempty(s)))
    s = move_to_end_comment(s, xml);
  if (!s)
    return (NULL);
  s += hempty(s);
  if (s[0] != '<')
    return (NULL);
  s += 1;
  name = my_strndup(s, sstrlen(s, " \t"));
  s += strlen(name) + hempty(s + strlen(name));
  if ((*tok = tokenize(s, xml, NULL, end)) == NULL)
    return (NULL);
  return (name);
}

char	*token_resolve(t_token **tok, t_token *link, char *s, t_token *prev)
{
  char	*r;

  r = NULL;
  if (!link)
    return (NULL);
  if (MATCH(link->name, s))
    r = link->token;
  else
    return (token_resolve(tok, link->next, s, link));
  if (!prev)
    *tok = link->next;
  else
    prev->next = link->next;
  free(link->name);
  free(link);
  return (r);
}

char	*xml_token(t_token **tok, char *s, FLAG lap, FD xml)
{
  if (!s)
    return (NULL);
  if (lap & INIT)
    return (token_ini(tok, s + hempty(s), xml,
		      (lap & A_END) ? (">") : ("/>")));
  else if (lap & RESOLVE)
    return (token_resolve(tok, *tok, s, NULL));
  else if (lap & END)
    {
      if (*tok == NULL)
	return (NULL);
      else
	return ((*tok)->next->name);
    }
  return (NULL);
}
