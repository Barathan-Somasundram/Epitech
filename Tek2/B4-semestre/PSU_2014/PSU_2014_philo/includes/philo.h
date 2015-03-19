/*
** philo.h for  in /home/somasu_b/rendu/PSU_2014_philo/includes
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sun Mar  1 19:18:03 2015 SOMASUNDRAM Barathan
** Last update Fri Mar  6 10:53:46 2015 SOMASUNDRAM Barathan
*/

#ifndef PHILO_H_
# define PHILO_H_

# define RICE		1
# define N_PHILO	7
# define TIME_EAT	2
# define TIME_THINK	5

typedef struct			s_philo
{
  int				id;
  int				rice;
  int				state;
  int				stick;
  int				time;
  struct s_philo		*prev;
  struct s_philo		*next;
}				t_philo;

pthread_mutex_t			my_mutex;

t_philo				*init_philo();
void				philo_eat(t_philo *philo);
void				philo_sleep(t_philo *philo);
void				philo_think(t_philo *philo, int stick);

#endif /* !PHILO_H_ */
