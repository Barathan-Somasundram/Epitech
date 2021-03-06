/*
** String.h for String in /home/somasu_b/rendu/piscine_cpp_d03
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Fri Jan  9 10:14:32 2015 SOMASUNDRAM Barathan
** Last update Fri Jan  9 11:51:25 2015 SOMASUNDRAM Barathan
*/

#ifndef STRING_H_
# define STRING_H_

#include <unistd.h>

typedef struct	string	String;

struct		string
{
  char		*str;
  void	(*assign_s)(String *this, String const *str);
  void	(*assign_c)(String *this, char const *s);
  void	(*append_s)(String *this, String const *ap);
  void	(*append_c)(String *this, char const *ap);
  char	(*at)(String *this, size_t pos);
};

void	StringInit(String *this, char const *s);
void	StringDestroy(String *this);

#endif /* !STRING_H_ */
