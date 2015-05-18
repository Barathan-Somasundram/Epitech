//
// GUI_OpenGL.hpp for  in /home/somasu_b/rendu/cpp_nibbler/sources
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sun Apr  5 13:35:22 2015 SOMASUNDRAM Barathan
// Last update Sun Apr  5 23:21:26 2015 SOMASUNDRAM Barathan
//

#ifndef OPENGL_HPP_
# define OPENGL_HPP_

#include <iostream>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "IGui.hpp"

class			OpenglNibbler : public IGui
{
private:
  int			_height;
  int			_width;
  int			_x;
  int			_y;
  SDL_Event		_event;
  SDL_Surface		*_screen;

public:
  OpenglNibbler();
  ~OpenglNibbler();

  int			initialize(int height, int width, std::vector<int> snake, char* map);
  int			getEvent(void);
  int			refresh(std::vector<int> snake, char* map);
  void			destroy(void);

  private:
  void			drawSquare(int x, int y, int size, unsigned char color[3]);
};

#endif /* !OPENGL_HPP_ */
