//
// opengl.cpp for  in /home/somasu_b/rendu/cpp_nibbler/sources
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sun Apr  5 13:35:34 2015 SOMASUNDRAM Barathan
// Last update Sun Apr  5 23:33:25 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <unistd.h>
#include "GUI_OpenGL.hpp"

OpenglNibbler::OpenglNibbler()
{
}

OpenglNibbler::~OpenglNibbler()
{
}

int					OpenglNibbler::initialize(int height, int width,
							   std::vector<int> snake, char* map)
{
  _x = width;
  _y = height;
  _height = height * 20;
  _width = width * 20;
  (void)snake;
  (void)map;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (1);
  if ((_screen = SDL_SetVideoMode(_width, _height, 32, SDL_OPENGL)) == NULL)
    return (1);
  SDL_Flip(_screen);
  glLoadIdentity();
  glOrtho(0, _height, _width, 0, 0, 1);
  glMatrixMode(GL_MODELVIEW);
  glDisable(GL_DEPTH_TEST);
  glClear(GL_COLOR_BUFFER_BIT);
  SDL_EventState(SDL_MOUSEBUTTONDOWN, SDL_IGNORE);
  SDL_EventState(SDL_MOUSEBUTTONUP, SDL_IGNORE);
  SDL_EventState(SDL_KEYUP, SDL_IGNORE);
  SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
  return (0);
}


void					OpenglNibbler::destroy(void)
{
  SDL_Quit();
}

int					OpenglNibbler::getEvent(void)
{
  _event.type = 0;
  SDL_PollEvent(&_event);
  if (_event.type == SDL_QUIT || _event.key.keysym.sym == SDLK_ESCAPE)
    return (ESCAPE);
  if (_event.key.keysym.sym == SDLK_RIGHT && _event.key.type == 2)
    return (R);
  if (_event.key.keysym.sym == SDLK_LEFT && _event.key.type == 2)
    return (L);
  if (_event.key.keysym.sym == SDLK_1 && _event.key.type == 2)
    return (ONE);
  if (_event.key.keysym.sym == SDLK_2 && _event.key.type == 2)
    return (TWO);
  if (_event.key.keysym.sym == SDLK_3 && _event.key.type == 2)
    return (THREE);
  return (FWD);
}

int					OpenglNibbler::refresh(std::vector<int> snake, char* map)
{
  (void)snake;
  int					i = 0;
  unsigned char				color_food[3] = {255, 0, 0};
  unsigned char				color_snake[3] = {0, 255, 0};

  while (i < _y * _x)
    {
      if (map[i] > 1 && map[i] < 9)
      	drawSquare(i / _x * 20, i % _x * 20, 20, color_food);
      else if (map[i] == 1)
	drawSquare(i / _x * 20, i % _x * 20, 20, color_snake);
      ++i;
    }
  SDL_GL_SwapBuffers();
  glClear(GL_COLOR_BUFFER_BIT);
  usleep(50000);
  return (0);
}

void					OpenglNibbler::drawSquare(int x, int y, int size, unsigned char color[3])
{
  glBegin(GL_QUADS);
  glColor3ub(color[0], color[1], color[2]);
  glVertex2f(x, y);
  glVertex2f(x + size, y);
  glVertex2f(x + size, y + size);
  glVertex2f(x, y + size);
  glEnd();
  glFlush();
}

extern "C"
{

  IGui*		_new(void)
  {
    IGui*	win = new OpenglNibbler();
    return (win);
  }

  void		_delete(IGui* win)
  {
    delete (win);
  }

}
