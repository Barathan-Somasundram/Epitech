//
// Nibbler.cpp for  in /home/somasu_b/rendu/cpp_nibbler/sources/algo
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Thu Apr  2 01:06:42 2015 SOMASUNDRAM Barathan
// Last update Sun Apr  5 23:36:26 2015 SOMASUNDRAM Barathan
//

#include "Nibbler.hpp"
#include <cstdlib>
#include <cstdio>
#include <time.h>

Nibbler::Nibbler(char** av)
{
  _x = atoi(av[1]);
  _y = atoi(av[2]);
  _libName = std::string(av[3]);
  _score = 0;
  _map = NULL;
  _snakeDead = 0;
  if (openDll(_libName) == 1)
    std::cout << "Error:" << std::endl;
  srand(time(NULL));
}

Nibbler::~Nibbler(void)
{
  if (_map != NULL)
    free(_map);
  closeDll();
}

int			Nibbler::initialize(void)
{
  void*			mem;
  int			i = 0;

  if ((mem = malloc(sizeof(char) * (_x * _y + 1))) == NULL)
    return (1);
  _map = reinterpret_cast<char*>(mem);
  while (i < _x * _y)
    _map[i++] = NOTHING;
  _snake.push_back(_y / 2 * _x + 3); //TODO: random
  _snake.push_back(_y / 2 * _x + 2); //TODO: random
  _snake.push_back(_y / 2 * _x + 1); //TODO: random
  _snake.push_back(_y / 2 * _x);
  _snakeHead = RIGHT; //TODO:
  genItem();
  refreshMap();
  return (0);
}

int			Nibbler::launch(void)
{
  int			event = -1;
  
  while (_snakeDead != 1)
    {
      event = _win->getEvent();
      if (event == 2)
	return (0);
      doEvent(&event);
      if (_snakeDead == 1)
	return (0);
      refreshMap();
      if (_snakeDead == 1)
	return (0);
      _win->refresh(_snake, _map);
      usleep(50000);
    }
  return (0);
}

int			Nibbler::getScore(void) const
{
  return (_score);
}

int			Nibbler::genItem(void)
{
  int			i = rand();

  i = i % (_x * _y);
  _map[i] = rand() % 7 + 2;
  return (0);
}

int			Nibbler::snakeEat(void)
{
  _snake.push_back(_snake[_snake.size() - 1] + 1);
  genItem();
  return (0);
}

void			Nibbler::snakeMove(int side)
{
  int			len = _snake.size();
  int			which = 0;

  if (_snakeHead == UP)
    {
      which = (side == R ? -1 : 1);
      _snakeHead = (side == R ? LEFT : RIGHT);
    }
  else if (_snakeHead == DOWN)
    {
      which = (side == R ? 1 : -1);
      _snakeHead = (side == R ? RIGHT : LEFT);
    }
  else if (_snakeHead == RIGHT)
    {
      which = (side == R ? -_x : _x);
      _snakeHead = (side == R ? UP : DOWN);
    }
  else if (_snakeHead == LEFT)
    {
      which = (side == R ? _x : -_x);
      _snakeHead = (side == R ? DOWN : UP);
    }
  while (--len >= 0)
    {
      if (len > 0)
	_snake[len] = _snake[len - 1];
      else
	_snake[len] = _snake[len] + which;
    }
  if (_snake[0] < 0 || _snake[0] > _x * _y
      || (_snake[0] % _x == 0 && (_snake[1] + 1) % _x == 0)
      || ((_snake[0] + 1) % _x == 0 && _snake[1] % _x == 0))
    _snakeDead = 1;
}

void			Nibbler::refreshMap(void)
{
  int			i = 0;
  int			len = _snake.size();

  while (i < _x * _y)
    {
      if (_map[i] == SNAKE)
	_map[i] = NOTHING;
      ++i;
    }
  i = 0;
  while (i < len)
    {
      if (_map[_snake[i]] > 1  && _map[_snake[i]] < 10)
	{
	  _score += _map[_snake[i]];
	  snakeEat();
	}
      if (_map[_snake[i]] == SNAKE)
	_snakeDead = 1;
      _map[_snake[i]] = SNAKE;
      ++i;
    }
}

void			Nibbler::snakeMoveFwd(void)
{
  int			len = _snake.size();
  int			plus = 0;

  if (_snakeHead == UP || _snakeHead == DOWN)
    plus = (_snakeHead == UP ? -_x : _x);
  else if (_snakeHead == RIGHT || _snakeHead == LEFT)
    plus = (_snakeHead == RIGHT ? 1 : -1);
  while (--len >= 0)
    {
      if (len > 0)
	_snake[len] = _snake[len - 1];
      else
	_snake[len] = _snake[len] + plus;
    }
  if (_snake[0] < 0 || _snake[0] > _x * _y
      || (_snake[0] % _x == 0 && (_snake[1] + 1) % _x == 0)
      || ((_snake[0] + 1) % _x == 0 && _snake[1] % _x == 0))
    _snakeDead = 1;
}

int			Nibbler::openDll(std::string libName) 
{
  _loader = new Dll<IGui>(libName);
  if ((_win = _loader->create()) == NULL)
    return (1);
  if (_win->initialize(_y, _x, _snake, _map) == 1)
    return (1);
  return (0);
}

void			Nibbler::closeDll(void)
{
  _loader->free(_win);
  delete _loader;
}

int			Nibbler::changeDll(int which)
{
  static const char	libs[3][22] =
    {
      "lib_nibbler_sdl.so",
      "lib_nibbler_ncurse.so",
      "lib_nibbler_opengl.so"
    };
  _win->destroy();
  closeDll();
  if (openDll(std::string(libs[which])) == 1)
    return (1);
  return (0);
}

void			Nibbler::doEvent(int* event)
{
  if (*event == FWD)
    snakeMoveFwd();
  else if (*event == L || *event == R)
    snakeMove(*event);
  else if (*event == ONE)
    changeDll(0);
    //std::cout << "ONE" << std::endl;
  else if (*event == TWO)
    changeDll(1);
    //std::cout << "TWO" << std::endl;
  else if (*event == THREE)
    changeDll(2);
    //std::cout << "THREE" << std::endl;;
}
