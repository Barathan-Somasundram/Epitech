/*
** init_term.c for alum-1 in /home/somasu_b/TEST/alum-1/sources/Initialize
**
** Made by somasu_b
** Login   <somasu_b@epitech.net>
**
** Started on  Thu Feb 13 15:48:19 2014 somasu_b
** Last update Sun Feb 16 21:35:03 2014 a
*/

#include <termios.h>
#include "../../includes/bonus.h"

void	guide(void)
{
  my_clear_full_screen();
  my_putstr("\tWelcome to the Marienbad game\n"
	    "In this game you will play with an IA\n"
	    "the loser is the one who burn the last match\n"
	    "\nPLAYER Keys:\t");
  my_putstr("-Left arrow to move the cursor to the left side\n"
	    "\t\t-Right arrow to move the cursor to the right side\n"
	    "\t\t-Upper arrow to access in the upper stage\n"
	    "\t\t-Lower arrow to access in the lower stage\n"
	    "\t\t-Space to select or deselect some match(es)\n"
	    "\t\t-Enter to delete what you have select"
	    " (it doesn't work if you no match(es) select\n");
  my_getchar();
  my_clear_full_screen();
}

int	init_term(t_term *backup, t_term *gameone, char **env)
{
  char	*term;

  if ((term = my_get_term(env)) == NULL)
    return (-1);
  if (tgetent(0, term) != 1)
    return (-1);
  if (term != NULL)
    free(term);
  if ((tcgetattr(0, backup)) == -1)
    return (-1);
  if ((tcgetattr(0, gameone)) == -1)
    return (-1);
  (*gameone).c_lflag &= ~ICANON;
  (*gameone).c_lflag &= ~ECHO;
  (*gameone).c_cc[VMIN] = 1;
  (*gameone).c_cc[VTIME] = 0;
  if ((tcsetattr(0, 0, gameone)) == -1)
    return (-1);
  tputs(tgetstr("vi", NULL), 1, my_putchar);
  return (0);
}
