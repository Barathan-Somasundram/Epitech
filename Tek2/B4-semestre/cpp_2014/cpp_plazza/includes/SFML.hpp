//
// SFML.hpp for  in /home/llyth/rendu/cpp_plazza/sources/SFML
//
// Made by llyth
// Login   <llyth@epitech.net>
//
// Started on  Sat Apr 25 15:42:24 2015 llyth
// Last update Sat Apr 25 21:29:18 2015 llyth
//

#ifndef SFML_HPP_
# define SFML_HPP_

# include <iostream>
# include <vector>
# include <cmath>
# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>

// # define TRUE			(1)
// # define FALSE			(0)
# define X_SIZE			(1280)
# define Y_SIZE			(720)
# define COOK_SIZE		(10)
# define BACKGROUND		("./background.jpg")
# define KITCHEN		("./kitchen.jpg")
# define FREECOOK		("./free_cook.jpg")
# define BUSYCOOK		("./busy_cook.jpg")

class				SFML
{
private :
  typedef struct		s_pos
  {
    int				x;
    int				y;
  }				t_pos;
  typedef struct		s_cook
  {
    t_pos			pos;
  }				t_cook;
  typedef struct		s_kitchen
  {
    t_pos			pos;
    bool			open;
    int				workingcook;
    std::vector<t_cook>		cooks;
  }				t_kitchen;
  int				_cpk;
  int				_cpl;
  int				_kitchensize;
  sf::RenderWindow		_window;
  sf::Event			_event;
  sf::Texture			_t_background;
  sf::Texture			_t_kitchen;
  sf::Texture			_t_freecook;
  sf::Texture			_t_busycook;
  sf::Sprite			_s_background;
  sf::Sprite			_s_kitchen;
  sf::Sprite			_s_freecook;
  sf::Sprite			_s_busycook;
  std::vector<t_kitchen>	_kitchens;

public :
  SFML(int cpk);
  ~SFML(void);

  bool				isOpen(void) const;
  void				closeWinEvent(void);
  void				displayArea(void);
  int				createKitchen(void);
  void				destroyKitchen(int kitchen);
  void				workingCook(int kitchen);
  void				notWorkingCook(int kitchen);
};

#endif	// !SFML_HPP_
