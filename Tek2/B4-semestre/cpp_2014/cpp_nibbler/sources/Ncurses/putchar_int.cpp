//
// putchar_int.cpp for nibbler in /home/moular_a/workspace/C++/nibbler
//
// Made by Antoine Moulard
// Login   <moular_a@epitech.net>
//
// Started on  Sat Apr  4 12:08:19 2015 Antoine Moulard
// Last update Sat Apr  4 13:50:24 2015 Antoine Moulard
//

#include <unistd.h>

int		my_putchar_int(int c)
{
  write(1, &c, 1);
  return (0);
}
