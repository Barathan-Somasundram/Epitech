/*
** Exo-1.h for  in /home/somasu_b/rendu/piscine_cpp_d09/ex-1
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Fri Jan 16 02:46:12 2015 SOMASUNDRAM Barathan
** Last update Fri Jan 16 03:11:49 2015 SOMASUNDRAM Barathan
*/

#ifndef EXO_H_
# define EXO_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct	s_cthulhu
{
  int		m_power;
  char		*m_name;
}		t_cthulhu;

typedef struct	s_koala
{
  t_cthulhu	m_parent;
  char		m_isALegend;
}		t_koala;

t_cthulhu	*NewCthulhu();
void		Attack(t_cthulhu*);
void		Sleeping(t_cthulhu*);
t_koala		*NewKoala(char*, char);
void		Eat(t_koala*);
static void	CthulhuInitializer(t_cthulhu*);
static void	KoalaInitializer(t_koala*, char*, char);

#endif /* !EXO_H_ */
