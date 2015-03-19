/*
** String.h for String in /home/somasu_b/rendu/piscine_cpp_d03
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Fri Jan  9 10:14:32 2015 SOMASUNDRAM Barathan
** Last update Fri Jan  9 10:55:30 2015 SOMASUNDRAM Barathan
*/

#ifndef STRING_H_
# define STRING_H_

typedef struct string
{
  char		*str;
}		String;

void	StringInit(String *this, char const *s);
void	StringDestroy(String *this);

#endif /* !STRING_H_ */
