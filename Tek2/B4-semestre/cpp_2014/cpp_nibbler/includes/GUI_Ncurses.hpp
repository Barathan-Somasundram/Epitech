//
// GUI_Qt.hpp for  in /home/somasu_b/rendu/snake/includes
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Tue Mar 10 16:57:49 2015 SOMASUNDRAM Barathan
// Last update Sun Apr  5 18:28:21 2015 Potier Guillaume
//

#ifndef GUI_NCURSES_HPP_
# define GUI_NCURSES_HPP_

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

#endif /* !GUI_NCURSES_HPP_ */
