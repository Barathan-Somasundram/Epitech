/*
** vm.h for corewar in /home/somasu_b/rendu/corewar/VM/retcode
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Sun Mar 30 22:46:14 2014 somasu_b
** Last update Sun Apr 13 19:21:17 2014 somasu_b
*/

#ifndef VM_H_
# define VM_H_

/*
** INCLUDES
*/

#include <unistd.h>
#include <stdlib.h>
#include "op.h"

/*
** DEFINES
*/

# define CARRY_MOD(param)	(param == 0 ? 1 : 0)
# define REG_NBR(nb)		(nb < 0 ? ((-nb) % REG_NUMBER) : (nb % REG_NUMBER))
# define PC(x)			(x < 0 ? ((-x) % MEM_SIZE) : (x % MEM_SIZE))

# define MAGIC_SIZE		4
# define PROG_SIZE_LENGTH	8
# define READ_SIZE		512
# define MAX_PROG_SIZE		1024
# define AFTER_CMD		1
# define PARAM_OCT		0

# define REG_01		0
# define REG_02		1
# define REG_03		2
# define REG_04		3
# define REG_05		4
# define REG_06		5
# define REG_07		6
# define REG_08		7
# define REG_09		8
# define REG_10		9
# define REG_11		10
# define REG_12		11
# define REG_13		12
# define REG_14		13
# define REG_15		14
# define REG_16		15

/*
** STRUTURES
*/

/*
** champion's struct with data
*/

typedef struct		s_champs
{
  header_t		header;
  op_t			opcode;

  unsigned char		commands[MEM_SIZE + 1];

  int			my_father;
  int			my_number;
  int			address;

  int			carry;
  int			pc;

  int			registers[REG_NUMBER];

  int			if_live;
  int			cycle_to_live;
  int			cycle_to_exec;

  struct s_champs	*prev;
  struct s_champs	*next;
}			t_champs;

/*
** battle royale winner's struct
*/

typedef struct		s_winner
{
  int			pid;
  char			name[PROG_NAME_LENGTH + 1];
  char			comment[COMMENT_LENGTH + 1];
}			t_winner;

/*
** virtual machine's struct
*/

typedef struct		s_core
{
  int			dump;
  int			nb_champ;
  int			proc;

  unsigned char		arena[MEM_SIZE + 1];
  int			nbr_live;
  int			cycle_of_now;
  int			cycle_to_die;

  t_winner		winner;

  int			(*retcode[16])(struct s_core *corewar,
				       t_champs **champs, t_champs **elem);
}			t_core;

/*
** PROTOTYPES
*/

int	kill_champs(t_champs **champs, t_champs *elem);
int	init_dump(t_core *corewar, int ac, char **av, int *begin);
int	init_corewar(t_core *corewar);
int	init_champs(t_champs **champs, int ac, char **av, int begin);
int	init_retcode(t_core *corewar);
int	check_champs_opt(int ac, char **av, int begin);
int	create_root_champ(t_champs **champs);
int	fill_champs_data(t_champs **elem, int number, int address, int fd);
int	stock_champs(char **av, t_champs **champs, int *begin);
int	my_join_champs(t_champs **champs, t_champs **elem, int tri);
int	places_champs(t_champs **champs, t_core *corewar);

/*
**
*/

int	move_pc(t_core *corewar, t_champs **elem, int why);
int	my_get_cmd(t_core *corewar, t_champs **elem);
int	my_get_value(t_core *corewar, int pc, int size);
int	my_get_param(t_core *corewar, t_champs *elem, int nb_param);

/*
** FIGHT
*/

int	lets_fight(t_core *corewar, t_champs *champs);

/*
** FINISH
*/

int	corewar_winner(t_core *corewar, t_champs *champs);
int	arena_dump(t_core *corewar, t_champs *champs);

/*
** RETCODE
*/

int	live(t_core *corewar, t_champs **champs, t_champs **elem);
int	load(t_core *corewar, t_champs **champs, t_champs **elem);
int	store(t_core *corewar, t_champs **champs, t_champs **elem);
int	add(t_core *corewar, t_champs **champs, t_champs **elem);
int	sub(t_core *corewar, t_champs **champs, t_champs **elem);
int	and(t_core *corewar, t_champs **champs, t_champs **elem);
int	or(t_core *corewar, t_champs **champs, t_champs **elem);
int	xor(t_core *corewar, t_champs **champs, t_champs **elem);
int	zjump(t_core *corewar, t_champs **champs, t_champs **elem);
int	load_index(t_core *corewar, t_champs **champs, t_champs **elem);
int	store_index(t_core *corewar, t_champs **champs, t_champs **elem);
int	cor_fork(t_core *corewar, t_champs **champs, t_champs **elem);
int	long_load(t_core *corewar, t_champs **champs, t_champs **elem);
int	long_load_index(t_core *corewar, t_champs **champs, t_champs **elem);
int	cor_long_fork(t_core *corewar, t_champs **champs, t_champs **elem);
int	aff(t_core *corewar, t_champs **champs, t_champs **elem);

#endif /* !_VM_H_ */
