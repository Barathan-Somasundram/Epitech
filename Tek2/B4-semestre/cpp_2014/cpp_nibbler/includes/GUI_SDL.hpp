//
// GUI_SDL.hpp for  in /home/somasu_b/rendu/snake/includes
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Tue Mar 10 16:56:38 2015 SOMASUNDRAM Barathan
// Last update Sat Apr  4 09:12:23 2015 SOMASUNDRAM Barathan
//

#ifndef GUI_SDL_HPP_
# define GUI_SDL_HPP_

#include <SDL/SDL.h>
#include "IGui.hpp"

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

class			SdlNibbler : public IGui
{
private:
  SDL_Surface		*screen;
  int			size_map;
  int			x_max;
  int			y_max;
  SDL_Event		event;
public:
  SdlNibbler();
  ~SdlNibbler();

  int		apply_snake(std::vector<int> snake);
  int		apply_item(char *map);

  int		initialize(int height, int width, std::vector<int> snake, char* map);
  int		refresh(std::vector<int> snake, char* map);
  int		getEvent(void);
  void		destroy(void);
};

#endif /* !GUI_SDL_HPP_ */
