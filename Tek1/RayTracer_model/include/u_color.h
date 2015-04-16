/*
** u_color.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu May 30 23:33:33 2013 vincent colliot
** Last update Wed Jun  5 00:11:07 2013 vincent colliot
*/

#ifndef U_COLOR_H_
# define U_COLOR_H_

typedef union u_color{
  unsigned char rgb[4];
  unsigned int i;
}		t_color;

# define A 0
# define R 2
# define G 1
# define B 0

# define N_C(n) (((n) > 255) ? (255) : (n))

#endif
