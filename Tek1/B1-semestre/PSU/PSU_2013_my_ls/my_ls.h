/*
** my_ls.h for my_ls in /home/somasu_b/my_files
** 
** Made by a
** Login   <somasu_b@epitech.net>
** 
** Started on  Sat Nov 30 00:09:02 2013 a
** Last update Sun Dec  1 20:36:32 2013 a
*/

#ifndef _MY_LS_H
# define _MY_LS_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

typedef struct	s_list
{
  struct stat	statbuf;
  char		*name;
  struct s_list	*next;
}		t_list;

void	my_putchar(char c);
int	my_strlen(char *str);
char	*my_strcat(char *dest, char *src);
void	my_putnbr(long nb);
void	date_time(char *info_modif);
char	*strcat_path(char *direct, char *file);
void	my_print_no_data(t_list *files);
void	l_data(t_list *tmp, struct passwd *pwd, struct group *grp);
void	my_print_l_data(t_list *files, int total);
void	recursive(t_list *files, char *directory, char *flag);
t_list	*my_put_in_list(t_list *files, struct stat statbuf,
			char *name, char *flag);
int	fill_data(struct dirent *dir_list, t_list **files,
		  char *directory, char *flag);
int	print_choice(t_list *files, char *flag, char *directory, int total);
int	my_ls(char *directory, char *flag);
char	*fill_flags(char *flags, char arg);
int	directory(int ac, char **av);
char	*my_strcpy(char *dest, char *src);
char	*my_strlowcase(char *s1);
char	fill_type(mode_t s_type);
void	tri_alpha(t_list **elem, t_list **files, char *name);
void	tri_time(t_list **elem, t_list **files, struct stat sb);

#endif /* !_MY_LS_H_ */
