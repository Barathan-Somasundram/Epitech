//
// resto.hpp for  in /home/somasu_b/rendu/cpp_plazza/includes
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sun Apr 26 18:18:07 2015 SOMASUNDRAM Barathan
// Last update Sun Apr 26 18:18:08 2015 SOMASUNDRAM Barathan
//

#ifndef RESTO_HPP_
# define RESTO_HPP_

#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <time.h>
#include "SFML.hpp"
#include "pizza.hpp"

extern pthread_mutex_t			my_mutex;

class				Ressources
{
public:
  typedef enum
    {
      contains_doe = 0,
      tomato,
      gruyere,
      ham,
      mushrooms,
      steak,
      eggplant,
      cheese,
      chief_love
    } _food;

private:
  std::vector<int>		_ressources;
  std::vector<time_t>		_time;

public:
  Ressources();
  ~Ressources();
  std::vector<int>		getRes();
  void				addRessources();
  void				delRessources(int id);
};

class				Kitchen
{
private:
  int				_fd_out;
  int				_fd_in;
  int				_time;
  int				_nb_cook;
  int				_multi;
  std::string			_name;
  Ressources			_ressources;
  std::vector<Pizza>		_pizza;

public:
  Kitchen(int id, std::string name_file, int nb_cook, int time, int multi);
  ~Kitchen();
  void				recup_order();
  void				cook_cmd();
  void				nb_cook_free();
  void				recup_name();
  void				recup_food();
  void				recup_end();
  void				addCuisto(int nb);
  void				delRessources(int id);
  std::vector<Pizza>		getPizza();
};

class				Cook
{
private:
  Kitchen			*_kitchen;
  static void			*apply_cook(void *param);
public:
  Cook(Kitchen *kitchen_act);
  ~Cook();
};

#endif
