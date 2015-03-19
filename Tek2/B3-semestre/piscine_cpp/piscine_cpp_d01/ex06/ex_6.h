/*
** ex6.h for ex6.h in /home/somasu_b/rendu/piscine_cpp_d01/ex06
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Thu Jan  8 00:12:30 2015 SOMASUNDRAM Barathan
** Last update Thu Jan  8 00:31:25 2015 SOMASUNDRAM Barathan
*/

#ifndef EX_6_H_
# define EX_6_H_

typedef union	u_foo3
{
  short		foo;
  short		bar;
}		t_foo3;

typedef struct	u_foo2
{
  short		foo;
  t_foo3	bar;
}		t_foo2;

typedef union	u_foo1
{
  t_foo2	foo;
  int		bar;
}		t_foo;

#endif /* !EX_6_H_ */
