// main.cpp for nibbler in /home/moular_a/rendu/cpp_nibbler/sources/Ncurses
//
// Made by Antoine Moulard
// Login   <moular_a@epitech.net>
//
// Started on  Fri Apr  3 21:55:07 2015 Antoine Moulard
// Last update Sun Apr  5 23:41:24 2015 SOMASUNDRAM Barathan
//

#include <unistd.h>
#include "GUI_Ncurses.hpp"

cursesNibbler::cursesNibbler() {}

cursesNibbler::~cursesNibbler() {}

int	cursesNibbler::initialize(int height, int width,
				    std::vector<int> snake, char *map)
{
  _height = height;
  _width = width;
  _snake = snake;
  _map = map;
  return (0);
}

bool		is_it_snake(int i, std::vector<int> snake)
{
  size_t	tmp;

  for (tmp = 0; tmp < snake.size(); tmp++)
    {
      if (i == snake[tmp])
	return (true);
    }
  return (false);
}

int		cursesNibbler::refresh(std::vector<int> snake, char *map)
{
  char		*term;
  int		res_tgetent;

  if ((term = getenv("TERM")) == NULL)
    {
      std::cout << "[ERROR NCURSES] : getenv" << std::endl;
      return (-2);
    }
  if ((res_tgetent = tgetent(0, term)) <= 0)
    {
      std::cout << "[ERROR NCURSES] : tgetent" << std::endl;
      return (-2);
    }
  // char		*res_tgetstr;

  // if ((res_tgetstr = tgetstr("cl", NULL)) == NULL)
  //   {
  //     std::cout << "[ERROR NCURSES] : tgetstr" << std::endl;
  //     return (-2);
  //   }
  // tputs(res_tgetstr, 1, my_putchar_int);

  int		i;
  i = -1;
  while (++i < _width + 1)    
    std::cout << "_";
  std::cout << std::endl;
  i = 0;
  while (i < _height * _width)
    {
      if (i && i % _width == 0)
	std::cout << std::endl;
      if ((is_it_snake(i, snake)) == true)
	std::cout << "X";
      else
	if (map[i] > 1)
	  std::cout << "@";
	else
	  std::cout << "-";
      ++i;
    }
  std::cout << std::endl;
  return (0);
}

int	cursesNibbler::getEvent(void)
{
  int	ch;
  int	i = 0;

  //  filter();
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  nodelay(stdscr,TRUE);
  while (i < 1)
    {
      ch = getch();
      usleep(100000);
      i++;
    }
  endwin();
  if (ch == 260)
    return (R);
  else if (ch == 261)
    return (L);
  else if (ch == 38)
    return (ONE);
  else if (ch == 39)
    return (TWO);
  else if (ch == 34)
    return (THREE);
  else
    return (FWD);
}

void	cursesNibbler::destroy(void)
{
  return;
}

extern "C"
{

  IGui*		_new(void)
  {
    IGui*	win = new cursesNibbler();
    return (win);
  }

  void		_delete(IGui* win)
  {
    delete (win);
  }

}
