//
// Nibbler.hpp for  in /home/somasu_b/rendu/cpp_nibbler/sources/algo
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Thu Apr  2 01:06:01 2015 SOMASUNDRAM Barathan
// Last update Sun Apr  5 23:25:55 2015 SOMASUNDRAM Barathan
//

# include <iostream>
# include <vector>
# include <exception>
# include <cstdlib>
# include <string>
# include <unistd.h>
# include "IGui.hpp"
# include "dll.hpp"

# define NOTHING	0
# define SNAKE		1
# define ITEM		2

# define RIGHT		0
# define LEFT		1
# define DOWN		2
# define UP		3

# define POSY(i, ymax)	i / ymax
# define POSX(i, ymax)	i % ymax
# define IDX(x,y,ymax)	y * ymax + x 


class			Nibbler
{
private:
  std::string		_libName;
  char*			_map;
  int			_score;
  int			_x;
  int			_y;
  
  Dll<IGui>		*_loader;		
  IGui			*_win;

  std::vector<int>	_snake;
  int			_snakeHead;
  int			_snakeDead;

public:
  Nibbler(char**);
  ~Nibbler();

  int			initialize(void);
  int			launch(void);
  int			getScore(void) const;

  int			genItem(void);

  int			snakeEat(void);
  int			snakeDead(void);
  void			snakeMove(int);
  void			snakeMoveFwd(void);

  int			openDll(std::string);
  void			closeDll();
  int			changeDll(int);

  void			refreshMap(void);
  void			doEvent(int*);
};
