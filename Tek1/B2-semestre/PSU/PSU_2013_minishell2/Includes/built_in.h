/*
** built_in.h for minishell2 in /home/somasu_b/TEST/mysh2
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Feb 23 21:31:12 2014 somasu_b
** Last update Sun Mar  9 17:57:55 2014 somasu_b
*/

#ifndef _BUILT_IN_H_
# define _BUILT_IN_H_

# include "mysh.h"

# define	CDHIR_ERRO	1
# define	ENVI_ERROR	2
# define	EXIT_ERROR	3
# define	SETENV_ERR	4
# define	UNSETENV_E	5

int	my_cd(char **cmd);
int	my_env(char **cmd);
int	my_exit(char **cmd, char **multi_cmd);
int	my_setenv(char **cmd);
int	my_unsetenv(char **cmd);

#endif /* !BUILT_IN_H_ */
