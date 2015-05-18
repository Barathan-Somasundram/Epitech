
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <iostream>
#include <sstream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "GUI_SDL.hpp"

SdlNibbler::SdlNibbler() {}

SdlNibbler::~SdlNibbler() {}

int		SdlNibbler::initialize(int height, int width,
				       std::vector<int> snake, char* map)
{
  (void)snake;
  (void)map;
  size_map = height * width;
  x_max = width;
  y_max = height;
  if(SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      std::cout << "Can't init SDL:  " <<  SDL_GetError() << std::endl;
      return (1);
    }
  screen = SDL_SetVideoMode(width * 50, height * 50, 16, SDL_HWSURFACE);
  SDL_WM_SetCaption("Nibbler SDL", NULL);
  if(screen == NULL)
    {
      std::cout << "Can't set video mode: " << SDL_GetError() << std::endl;
      return 1;
    }
  return (0);
}

int		SdlNibbler::getEvent()
{
  SDL_Event	event;

  event.type=0;
  SDL_PollEvent(&event);
  if (event.type == 0)
    return (FWD);
  if (event.type == 12 || (event.key.type == 3 && event.key.keysym.sym == 27))
    return (ESCAPE);
  if (event.key.keysym.sym == 276 && event.key.type == 2)
    return (R);
  if (event.key.keysym.sym == 275 && event.key.type == 2)
    return (L);
  if (event.key.keysym.sym == 38 && event.key.type == 2)
    return (ONE);
  if (event.key.keysym.sym == 233 && event.key.type == 2)
    return (TWO);
  if (event.key.keysym.sym == 34 && event.key.type == 2)
    return (THREE);
  return (FWD);
}

SDL_Surface	*load_image(std::string filename)
{
  SDL_Surface* loadedImage = NULL; 
  SDL_Surface* optimizedImage = NULL;

  loadedImage = SDL_LoadBMP( filename.c_str() );

  if( loadedImage != NULL ) { 
    optimizedImage = SDL_DisplayFormat( loadedImage ); 
    SDL_FreeSurface( loadedImage ); 
  }
  return optimizedImage; 
}

void			apply_surface( int x, int y, std::string path, SDL_Surface* screen)
{
  SDL_Rect		coor;
  SDL_Surface		*img;

  img = IMG_Load(path.c_str());
  if (img == NULL)
    return ;
  coor.x = x;
  coor.y = y;
  SDL_BlitSurface(img, NULL, screen, &coor);
}

int			apply_head(std::string img, SDL_Surface* screen, std::vector<int> snake, int pos, int y)
{
  int			i = 0;
  int			j = 0;

  if (POSX(snake[pos], y) == POSX(snake[pos + 1], y))
    i -= 12;
  else
    j -= 12;
  apply_surface((POSX(snake[pos], y) * 50) + i, (POSY(snake[pos], y) * 50) + j, img, screen);
  return (1);
}

std::string		recup_vect(int pos1, int pos2, int max_y)
{
  std::stringstream	vect;

  vect.str("");
  vect << POSX(pos2, max_y) - POSX(pos1, max_y) << "." << POSY(pos2, max_y) - POSY(pos1, max_y);
  return (vect.str());
}

std::string		generate_head(int i, std::vector<int> snake, int max)
{
  std::stringstream	img;

  img.str("");
  img << "./images/SDL/Shenron/shenron_part_1,";
  img << recup_vect(snake[i], snake[i + 1], max) << ".png";
  return (img.str());
}

std::string		generate_body(int i, std::vector<int> snake, int max)
{
  std::stringstream	img;

  img.str("");
  img << "./images/SDL/Shenron/shenron_part_2,";
  if (snake[i - 1] < snake[i + 1])
    {
      img << recup_vect(snake[i + 1], snake[i], max);
      img << "," << recup_vect(snake[i - 1], snake[i], max) << ".png";
    }
  else
    {
      img << recup_vect(snake[i - 1], snake[i], max);
      img << "," << recup_vect(snake[i + 1], snake[i], max) << ".png";
    }
  return (img.str());
}

std::string		generate_tail(int i, std::vector<int> snake, int max)
{
  std::stringstream	img;

  img.str("");
  img << "./images/SDL/Shenron/shenron_part_3,";
  img << recup_vect(snake[i], snake[i - 1], max) << ".png";
  return (img.str());
}

int			SdlNibbler::apply_snake(std::vector<int> snake)
{
  int			len = snake.size();
  std::string		img;

  for (int i = 0; i < len; i++)
    {
      if (i == 0)
	{
	  img = generate_head(i, snake, x_max);
	  apply_head(img, screen, snake, i, x_max);
	}
      else if (i == len - 1)
	{
	  img = generate_tail(i, snake, x_max);
	  apply_surface(POSX(snake[i], x_max) * 50, POSY(snake[i], x_max) * 50, img, screen);
	}
      else
	{
	  img = generate_body(i, snake, x_max);
	  apply_surface(POSX(snake[i], x_max) * 50, POSY(snake[i], x_max) * 50, img, screen);
	}
    }
  return (1);
}

int			SdlNibbler::apply_item(char *map)
{
  std::stringstream	img;

  for (int pos = 0; pos < size_map; pos++)
    {
      if (map[pos] > 1)
	{
	  img.str("");
	  img << "./images/SDL/Dragon Ball/dragon_ball_";
	  img << (int)map[pos] - 1 << ".png";
	  apply_surface(POSX(pos, x_max) * 50, POSY(pos, x_max) * 50, img.str(), screen);
	}
    }
  return (1);
}

int		SdlNibbler::refresh(std::vector<int> snake, char* map)
{
  apply_surface(0, 0, "./images/SDL/Back_SDL.png", screen);
  apply_snake(snake);
  apply_item(map);
  SDL_Flip(screen);
  return (1);
}

void		SdlNibbler::destroy()
{
  SDL_Quit();
  return ;
}

extern "C"
{

  IGui*		_new(void)
  {
    IGui*	win = new SdlNibbler();
    return (win);
  }

  void		_delete(IGui* win)
  {
    delete (win);
  }

}
