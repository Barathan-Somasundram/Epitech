/*
** elcrypt.h for  in /home/somasu_b/rendu/elcrypt
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sun Mar 15 18:36:33 2015 SOMASUNDRAM Barathan
** Last update Sun Mar 15 18:50:46 2015 SOMASUNDRAM Barathan
*/

#ifndef ELCRYPT_H_
# define ELCRYPT_H_

# define O_RIGHTS	0666
# define BINAIRE	"01"
# define DECIMAL	"0123456789"
# define HEXADECIMAL1	"0123456789ABCDEF"
# define HEXADECIMAL2	"0123456789abcdef"
# define DECI_ASCII	""
# define ASCII		"ASCII"
# define HEXA_SIGN	"0x"
# define BINA_SIGN	"%"

typedef long int	t_b64;

typedef union	u_key
{
  long int	key;
  int		split[2];
}		t_key;

typedef union	u_bloc32
{
  int		bloc;
  char		split[4];
}		t_bloc32;

typedef struct		s_elcrypt
{
  int			action;
  char			*in;
  int			fd_in;
  char			*out;
  int			fd_out;
  char			*key;
  t_b64			key_dec;
  char			*key_bin;
}			t_elcrypt;

int			recup_arg(int ac, char **av, t_elcrypt *param);
int			flag_action(char **av, int arg, t_elcrypt *param);
int			flag_file(int ac, char **av, int arg, t_elcrypt *param);
int			flag_key(int ac, char **av, int arg, t_elcrypt *param);
char			*bin32_to_string(char *bin);
char			*rotate_key(char *key, int turn);
char			*convert_key_bin(t_b64 nbr);
char			*convert_bin(char *key, int size_key);
t_b64			get_key(char* key);
char*			get_base(char* key);
t_b64			getnbr_base(char* str, char* base);
t_b64			my_pow(t_b64, int);
int			decrypt(t_elcrypt *p);
int			crypt(t_elcrypt *p);
char			*cut_bloc(char *block, int part);
char			*convert_or(char *bloc_32, char *key);

#endif	/* !ELCRYPT_H_ */
