/*
** my_calc.c for 108monstre in /home/song_k/rendu/108monstre
**
** Made by song_k
** Login   <song_k@epitech.net>
**
** Started on  Fri Mar 14 23:17:03 2014 song_k
** Last update Sat Mar 22 15:17:17 2014 song_k
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	my_calc(float a, int nmax)
{
  float	i;
  double	res;
  int	ct;
  FILE	*fd;

  if ((fd = fopen("108monstre.dat", "w")) == NULL)
    return (-1);
  i = -2.00000;
  while (i <= 2.00010)
    {
      res = 0.00000;
      ct = 0;
      while (ct < nmax)
	{
	  res = res + (cos(pow(a, ct) * M_PI * i) / pow(2, ct));
	  ++ct;
	}
      fprintf(fd, "%g %g\n", i, res);
      i += 0.0001;
    }
  fclose(fd);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac == 3)
    {
      if (atof(av[1]) < 2.0)
	return (printf("The first argument must be higher than two\n"));
      if (atoi(av[2]) < 0)
	return (printf("The second argument must be positiv\n"));
      printf("LEGENED :\na = %g, Nmax = %d\n\n", atof(av[1]), atoi(av[2]));
      my_calc(atof(av[1]), atoi(av[2]));
      printf("Press ENTER to exit\n");
      if (execlp("./108monstre.gnu", "108monstre", NULL) == -1)
	return (printf("Has error has happend while opening the graphic window\n"));
      if (execlp("rm", "rm", "108monstre.dat", NULL) == -1)
	return (printf("Has error has happend while opening the graphic window\n"));
    }
  else
    printf("USAGE : ./calc [a] [Nmax]\n");
  return (0);
}
