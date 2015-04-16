/*
** lem-in.h for lem-in in /home/song_k/rendu/lemin-2016-song_k/workgit/song_k/inc
**
** Made by song_k
** Login   <song_k@epitech.net>
**
** Started on  Fri Apr 11 14:31:44 2014 song_k
** Last update Sun May  4 23:03:21 2014 somasu_b
*/

#ifndef LEMIN_H_
# define LEMIN_H_

# define BUF_LEN	512

# define NUM_VAL	"-0123456789"
# define START_TAG	"##start"
# define END_TAG	"##end"

# define CHAR_ERR	"A undesirable character has been spotted\n"
# define EMPT_FIL	"Oops an Empty File\n"
# define BAD_NAME	"There's no name for this block\n"
# define BLOC_FAIL	"Missing block\n"
# define PARS_ERR	"Parsing Error\n"
# define NO_LINKS	"Oops no links available please make another one\n"
# define LINKS_PARS	"This line isn't correctly syntaxed\n"
# define BAD_LINKS	"It appeared that the link doesn't exist\n"
# define NO_WAY		"Sorry That map is not resolvable\n"

typedef struct	s_list
{
  int		bloc;
  int		my_id;
  int		remains;
  char		*name;
  struct s_list	*next;
}		t_list;

typedef struct	s_bloc
{
  int		here;
  int		posx;
  int		posy;
  char		*name;
  t_list	*links;
}		t_bloc;

typedef struct	s_data
{
  int		nb_ant;
  int		nb_bloc;
  char		**maze_data;
  t_bloc	*data;
}		t_data;

int	my_isnum(char *str);
int	my_getnbr(char *str);
int	my_strlen(char *str);
int     my_strcmp(const char *s1, const char *s2);
int     my_strncmp(const char *s1, const char *s2, const int n);
int	my_putnbr(int nb);

char	*my_realloc(char *s1, char *s2);
char	*my_strdup(char *s1);
char	**my_str_to_wordtab(char *str, char sep);

char	*my_fillinstr(const int fd);
char	*get_next_line(const int fd);

int	my_checkcharfromstr(char *str, char *lib);

void	my_putstr(char *str, const int fd);

int	fillbloc(t_data *way);

int	filllink(t_data *way, int *ct);

int	cleanway(t_data *way);
int	main_algo(t_data *way);

#endif /* LEMIN_H_ */
