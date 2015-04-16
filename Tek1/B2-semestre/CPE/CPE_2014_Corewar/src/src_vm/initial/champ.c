/*
** champ_opt.c for corewar in /home/somasu_b/corewar/corewar/vm/initial
**
** Made by a
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Apr 13 16:42:10 2014 a
** Last update Sun Apr 13 18:42:29 2014 a
*/

#include <fcntl.h>
#include "vm.h"
#include "my_strings.h"

int	load_address(char **av, int *begin)
{
  int	address;

  address = -1;
  if (my_strcmp(av[*begin], "-a") == 0)
    {
      address = my_get_nbr(av[*begin + 1]);
      if (address <= 0)
	return (my_perror("Error : load_address cannot be 0 or negativ\n", NULL));
      address = address % MEM_SIZE;
      *begin = *begin + 2;
      return (address);
    }
  return (-2);
}

int	load_number(char **av, int *begin, char numbers[4])
{
  int	i;
  int	n;

  n = 0;
  if (my_strcmp(av[*begin], "-n") == 0)
    {
      n = my_get_nbr(av[*begin + 1]);
      if (n <= 0)
	return (my_perror("Error : prog_number cannot be 0 or negativ\n", NULL));
      if (n > 4)
	return (my_perror("Error : prog_number cannot be higher than 4\n", NULL));
      if (numbers[n - 1] == '1')
	return (my_perror("Error : prog_number already used\n", NULL));
      *begin = *begin + 2;
      return (n);
    }
  i = 0;
  while (i < 4 && numbers[n] == '1')
    ++n;
  return (n + 1);
}

int		stock_champ(char **av, t_champs **champs, int *begin)
{
  t_champs	*elem;
  static char	numbers[4] = "0000";
  int		address;
  int		number;
  int		fd;

  fd = 0;
  if ((number = load_number(av, begin, numbers)) == -1)
    return (-1);
  numbers[number - 1] = '1';
  if ((address = load_address(av, begin)) == -1)
    return (-1);
  if ((fd = open(av[*begin], O_RDONLY)) == -1)
    return (my_perror("Error : Cannot open champion file : ", av[*begin]));
  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (-1);
  if (fill_champs_data(&elem, number, address, fd) == -1)
    return (-1);
  if (my_join_champs(champs, &elem, 1) == -1)
    return (-1);
  if (close(fd) == -1)
    return (-1);
  return (0);
}
