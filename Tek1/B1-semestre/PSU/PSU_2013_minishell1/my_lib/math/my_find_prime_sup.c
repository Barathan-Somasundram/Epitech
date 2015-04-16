/*
** my_find_prime_sup.c for my_find_prime_sup in /home/somasu_b/Desktop/my_lib/math
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Wed Dec 18 10:41:17 2013 a
** Last update Wed Dec 18 19:29:40 2013 a
*/

#include "../includes/my_lib.h"

int	my_find_prime_sup(int nb)
{
  while (my_is_prime(nb) == 0)
    nb = nb + 1;
  return (nb);
}
