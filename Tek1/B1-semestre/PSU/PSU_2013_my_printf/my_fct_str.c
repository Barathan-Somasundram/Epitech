/*
** my_fct_str.c for my_printf in /home/somasu_b/rendu/PSU_2013_my_printf
** 
** Made by a
** Login   <somasu_b@epitech.net>
** 
** Started on  Wed Nov 13 17:46:41 2013 a
** Last update Sat Nov 16 20:16:14 2013 a
*/

int	my_put_char(char c, int size)
{
  write(1, &c, 1);
  return (size + 1);
}

int	my_str_len(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

int	my_put_str(char *str, int size)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      size = my_put_char(str[i], size);
      i = i + 1;
    }
  return (size);
}
