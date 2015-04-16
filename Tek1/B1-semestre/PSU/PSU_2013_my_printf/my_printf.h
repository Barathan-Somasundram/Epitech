/*
** my_printf.h for my_printf.h in /home/somasu_b/rendu/PSU_2018_my_printf
** 
** Made by a
** Login   <somasu_b@epitech.net>
** 
** Started on  Tue Nov 12 10:43:55 2013 a
** Last update Sun Nov 17 19:06:23 2013 a
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

int	my_put_unsigned_nbr_base(int nb, char *base);
int	my_put_dec(va_list ap, int size);
int	my_put_un_dec(va_list ap, int size);
int	my_put_un_bin(va_list ap, int size);
int	my_put_un_oct(va_list ap, int size);
int	my_put_un_hex_low(va_list ap, int size);
int	my_put_un_hex_up(va_list ap, int size);
int	my_put_char_ap(va_list ap, int size);
int	my_put_str_ap(va_list ap, int size);
int	my_put_unprintable(va_list ap, int size);
int	my_put_point(va_list ap, int size);
int	my_put_long(va_list ap, int size);

#endif /* !MY_PRINTF */
