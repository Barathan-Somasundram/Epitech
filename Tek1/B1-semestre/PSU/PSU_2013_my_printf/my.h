/*
** my.h for my.h in /home/somasu_b/rendu/tab
** 
** Made by a
** Login   <somasu_b@epitech.net>
** 
** Started on  Sun Nov 17 19:20:20 2013 a
** Last update Sun Nov 17 19:43:10 2013 a
*/

#ifndef MY_H_
# define MY_H_

int	my_put_nbr_base(int nb, char *base, int size);
int	my_put_long_nbr_base(long nb, char *base, int size);
int     my_put_unsigned_nbr_base(int nb, char *base, int size);
int	my_put_char(char c, int size);
int	my_str_len(char *str);
int	my_put_str(char *str, int size);
int     my_put_dec(va_list ap, int size);
int     my_put_un_dec(va_list ap, int size);
int     my_put_un_bin(va_list ap, int size);
int     my_put_un_oct(va_list ap, int size);
int     my_put_un_hex_low(va_list ap, int size);
int     my_put_un_hex_up(va_list ap, int size);
int     my_put_char_ap(va_list ap, int size);
int     my_put_str_ap(va_list ap, int size);
int     my_put_unprintable(va_list ap, int size);
int     my_put_point(va_list ap, int size);
int     my_put_long(va_list ap, int size);
int	my_printf(const char *format, ...);

#endif /* !MY_H */
