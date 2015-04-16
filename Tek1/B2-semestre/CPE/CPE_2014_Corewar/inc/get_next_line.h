/*
** get_next_line.h for getnextline in /home/taille_a/Travail/getnext_line$/TP1
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Mon Nov 18 14:45:48 2013 taille_a
** Last update Tue Apr  8 02:11:39 2014 taille_a
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define BUFFSIZE 1024

char *get_next_line(const int);

typedef struct	s_cursor
{
  int		back;
  int		save;
  int		util;
}		t_cursor;

#endif /* !GET_NEXT_LINE_H_ */
