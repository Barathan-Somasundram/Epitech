/*
** ncurses_nibbler.h for nibbler in /home/moular_a/workspace/C++/nibbler
**
** Made by Antoine Moulard
** Login   <moular_a@epitech.net>
**
** Started on  Sat Apr  4 00:33:12 2015 Antoine Moulard
// Last update Sat Apr  4 15:04:13 2015 SOMASUNDRAM Barathan
*/

#ifndef _NCURSES_NIBBLER_H_
# define _NCURSES_NIBBLER_H_

# include <iostream>
# include <curses.h>
# include <ncurses/curses.h>
# include <term.h>
# include <stdlib.h>
# include "IGui.hpp"

class			cursesNibbler : public IGui
{
 public:
  cursesNibbler();
  ~cursesNibbler();

  int			initialize(int, int, std::vector<int>, char*);
  int			refresh(std::vector<int>, char*);
  int			getEvent(void);
  void			destroy(void);

 private:
  int			_height;
  int			_width;
  std::vector<int>	_snake;
  char			*_map;
};

int             my_putchar_int(int c);

#endif /* !_NCURSES_NIBBLER_H_ */
