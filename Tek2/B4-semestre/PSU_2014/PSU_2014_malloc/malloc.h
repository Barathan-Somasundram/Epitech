/*
** malloc.h for malloc in /home/song_k/rendu/PSU_2014_malloc
**
** Made by song kevin
** Login   <song_k@epitech.net>
**
** Started on  Wed Jan 28 13:40:17 2015 song kevin
** Last update Sun Feb 15 23:41:27 2015 song kevin
*/

#ifndef MALLOC_H_
# define MALLOC_H_

/*
** INCLUDES
*/
# include <unistd.h>

/*
** ENUM
*/
enum
  {
    IS_FREE,
    NOT_FREE,
    IS_HEAD,
    NOT_HEAD
  };

/*
** STRUCTURES
*/
typedef struct	s_data
{
  void		*ptr;
  size_t	size;
  size_t	lost;
  char		free;

  struct s_data	*next;
  struct s_data	*prev;
}		t_data;

extern t_data		*g_mem;
extern size_t		g_maxsize;
/*
** FUNCTIONS PROTOTYPES
*/
void	*malloc(size_t taille);
void	free(void *ptr);
void	*re_use_mem(t_data*, size_t);
void	*find_in_mem(size_t size, char *check);
void	*realloc(void *ptr, size_t size);
void	*calloc(size_t nmemb, size_t size);
void	show_list(void);
void	show_alloc_mem(void);

#endif /* !MALLOC_H_ */
