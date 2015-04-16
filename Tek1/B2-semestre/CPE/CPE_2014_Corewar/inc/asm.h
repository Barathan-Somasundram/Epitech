
/*
** asm.h for corewar in /home/taille_a/Travail/corewar/vm/CPE_2014_corewar/taille_a/ASM
**
** Made by taille_a
** Login   <taille_a@epitech.net>
**
** Started on  Mon Mar 24 11:01:08 2014 taille_a
** Last update Sun Apr 13 18:01:16 2014 a
*/

#ifndef ASM_H_
# define ASM_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "op.h"

# define RIGHTS (S_IRUSR| S_IWUSR| S_IRGRP| S_IWGRP| S_IROTH| S_IWOTH)
# define BIG 1
# define LITTLE 0

typedef struct	s_toke
{
  char		*buff;
  struct s_toke	*next;
  struct s_toke *prev;
}		t_toke;

typedef struct	s_list
{
  int		line;
  char		*buff;
  char		*ne_buff;
  char		*is_a_label;
  int		byte_used;
  int		tab[3];
  int		op_code;
  char		code;
  t_toke	*token_list;
  struct s_list	*next;
  struct s_list *prev;
}		t_list;

typedef struct	s_champ
{
  int		magic;
  char		*name;
  int		prog_size;
  char		*comment;
}		t_champ;

int		write_cor_file(t_list **, header_t *, char *);
char		*put_byte_to_buff(char *, int, int, int);
char		*put_value_to_buffer(t_list **, t_toke *, int, char *);
int		search_label(t_list **, char *);
int		label_search_up(t_list **, char *);
int		label_search_down(t_list **, char *);
int		parse_code_rmv(t_list **);

/*
** Fonction parsing.
*/

int		parse_code(t_list **, header_t *);
int		parse_comment(t_list **, header_t *, int);
char		*my_get_token(char *, int *);
int		parser_command(t_list **);
void		opcode_init(char *tab[17]);
void		opcodefunc_init(int (*tab[17])(t_list **));
int		get_comment(char *, int *);

/*
** Verification des arguments.
*/

int		verif_register(char *);
int		verif_direct(char *);
int		verif_direct2(char *);
int		verif_label(char *);
int		verif_indirect(char *);
int		verif_existing_label(t_list **, char *);
int		verif_label_in_dir(char *);

/*
** Fonction Op_code.
*/

int		ld(t_list **);
int		live(t_list **);
int		st(t_list **);
int		and(t_list **);
int		sub(t_list **);
int		add(t_list **);
int		or(t_list **);
int		xor(t_list **);
int		zjmp(t_list **);
int		ldi(t_list **);
int		fork_asm(t_list **);
int		sti(t_list **);
int		lld(t_list **);
int		lldi(t_list **);
int		aff(t_list **);
int		lfork(t_list **);

/*
** Fonction utilisé dans or/xor/and.
*/

int		get_type_argument(char *);
char		get_byte_code(int *);
int		get_bytes_used(int *);

# define LINE_TOO_LONG -3
# define INVALID_FILE -2
# define NOTHING -1

#endif /* !ASM_H_ */
