/*
** my.h for corewar in /home/taille_a/Travail/corewar/vm/CPE_2014_corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Mon Mar 24 16:24:28 2014 taille_a
** Last update Sat Apr 12 16:30:28 2014 taille_a
*/

#ifndef MY_H_
# define MY_H_

#include "asm.h"

int		my_strlen(char *);
char		*my_strcpy(char *, char *);
char		*my_strcat(char *, char *);
int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);
void		my_strncpy(char *, char *, int , int);
long		my_getnbr(char *);
int		error_main(char *);
char		*epur_str(char *, int);
void		my_exit(t_list **, char *);
int		swap_byte(int);
int		my_get_endian();
int		error_invalid_file(int, char *);
void		my_putnbr(int);
int		compile_msg(header_t *, char *, int);
void		verif_value(t_list **, long, int, char *);
int		fct_err_line(int, char *, int);
int		fct_msg_error(char *, int);
char		*my_epurstr(char *);
void		free_all(t_list **);
void		init_value_in_list(t_list **);

#endif /* !MY_H_ */
