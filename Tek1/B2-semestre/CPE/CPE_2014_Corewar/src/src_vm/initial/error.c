/*
** error.c for corewar in /home/somasu_b/rendu/corewar/VM/retcode/test
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Tue Apr  1 17:52:43 2014 somasu_b
** Last update Sun Apr 13 18:40:02 2014 a
*/

#include "vm.h"
#include "my_strings.h"

int	check_prog_number(int ac, char **av, int *begin, char **numbers)
{
  int	prog_number;

  prog_number = 0;
  if (my_strcmp(av[*begin], "-n") != 0)
    return (0);
  else
    {
      if (*begin + 2 < ac)
	{
	  prog_number = my_get_nbr(av[*begin + 1]);
	  if (prog_number <= 0 || prog_number > 4)
	    return (my_perror("Error : the prog_number must be"
			      " between 1 and 4\n", NULL));
	  if ((*numbers)[prog_number - 1] == '1')
	    return (my_perror("Error : prog_number must be unique\n", NULL));
	  else
	    (*numbers)[prog_number - 1] = '1';
	  *begin = *begin + 2;
	}
      else
	return (my_perror("Error : there is may be no champion\n", NULL));
    }
  return (0);
}

int	check_load_address(int ac, char **av, int *begin)
{
  int	address;

  address = 0;
  if (my_strcmp(av[*begin], "-a") != 0)
    return (0);
  else
    {
      if (*begin + 2 < ac)
	{
	  address = my_get_nbr(av[*begin + 1]);
	  if (address < 0 || address > MEM_SIZE - 1)
	    return (my_perror("Error : load_address must be between 0 and "
			      "MEM_SIZE\n (look in op.h for the value of "
			      "MEM_SIZE\n", NULL));
	  *begin = *begin + 2;
	}
      else
	return (my_perror("Error : ther is may be no champion\n", NULL));
    }
  return (0);
}

int	check_file_cor(char **av, int begin, int *nb_champs)
{
  int	len;

  len = my_strlen(av[begin]);
  if (len < 4)
    return (my_perror("Error : the file is not a champion (.cor)\n",
		      NULL));
  else if (my_strcmp(&(av[begin][len - 4]), ".cor") != 0)
    return (my_perror("Error : invalid file format\n", NULL));
  *nb_champs = *nb_champs + 1;
  return (0);
}

int	check_nb_champs(int nb_champs)
{
  if (nb_champs == 0)
    return (my_perror("Error : Too few arguments\ncorewar minimum champion"
		      " is one(1)\nUsage: corewar [-dump number of cycles]"
		      " [[-n programme number][-a load address]] file_name[.s]\n"
		      , NULL));
  if (nb_champs > 4)
    return (my_perror("Error : Too many champions\ncorewar maximum champions"
		      " is four(4)\nUsage: corewar [-dump number of cycles]"
		      " [[-n programme number][-a load address]] file_name[.s]\n"
		      , NULL));
  return (0);
}

int	check_champs_opt(int ac, char **av, int begin)
{
  char	*prog_numbers;
  int	nb_champs;
  int	i;

  i = 0;
  nb_champs = 0;
  if ((prog_numbers = malloc(sizeof(char) * 4)) == NULL)
    return (-1);
  while (i < 4)
    prog_numbers[i++] = '0';
  while (begin < ac)
    {
      if (check_prog_number(ac, av, &begin, &prog_numbers) == -1)
	return (-1);
      if (check_load_address(ac, av, &begin) == -1)
	return (-1);
      if (check_file_cor(av, begin, &nb_champs) == -1)
	return (-1);
      begin = begin + 1;
    }
  if (check_nb_champs(nb_champs) == -1)
    return (-1);
  free(prog_numbers);
  return (0);
}
