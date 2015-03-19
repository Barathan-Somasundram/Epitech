/*
** String.h for String in /home/somasu_b/rendu/piscine_cpp_d03
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Fri Jan  9 10:14:32 2015 SOMASUNDRAM Barathan
** Last update Fri Jan  9 11:25:56 2015 SOMASUNDRAM Barathan
*/

#ifndef STRING_H_
# define STRING_H_

typedef struct string	String;

struct		string
{
  char		*str;
  void	(*assign_s)(String *this, String const *str);
  void	(*assign_c)(String *this, char const *s);
};

void	StringInit(String *this, char const *s);
void	StringDestroy(String *this);

#endif /* !STRING_H_ */
