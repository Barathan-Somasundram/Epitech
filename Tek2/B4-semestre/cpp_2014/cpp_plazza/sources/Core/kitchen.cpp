//
// kitchen.cpp for  in /home/somasu_b/rendu/cpp_plazza/sources/Core
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Tue Apr  7 12:46:04 2015 SOMASUNDRAM Barathan
// Last update Tue Apr  7 12:46:05 2015 SOMASUNDRAM Barathan
//

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <pthread.h>
#include "resto.hpp"
#include "pizza.hpp"

Kitchen::Kitchen(int id, std::string name_file, int nb_cook, int time, int multi) : _time(time), _nb_cook(nb_cook), _multi(multi)
{
  std::stringstream	name;
  Ressources		tmp;

  name << "Kitchen n°" << id;
  _name = name.str();
  _fd_in = open(name_file.c_str(), O_WRONLY);
  _fd_out = open(name_file.c_str(), O_RDONLY);
  _ressources = tmp;
  // for (int i = 0; i < nb_cook; ++i)
  //   Cook(this);
}

Kitchen::~Kitchen() {}

void				Kitchen::recup_order()
{
  char			buffer[512];
  int			size;

  buffer[0] = 0;
  while (strcmp(buffer, "end") != 0)
    {
      // _ressources.addRessources();
      std::cout << "Wait Instruction from Reception..." << std::endl;
      if ((size = read(_fd_out, &buffer, 512)) < 0)
        return ;
      buffer[size] = 0;
      std::cout << "Instruction => [" << buffer << "] " << std::endl;
      if (strcmp(buffer, "free") == 0)
      	nb_cook_free();
      else if (strcmp(buffer, "name") == 0)
      	recup_name();
      else if (strcmp(buffer, "ingredient") == 0)
      	recup_food();
      else if (strcmp(buffer, "finished") == 0)
      	recup_end();
      else if (buffer[0] == '>')
  	{
	  Pizza		pizza(std::string(buffer), _multi);
  	  std::cout << "Preparation de la commande => " << buffer + 1 << std::endl;
	  _pizza.push_back(pizza);
  	}
    }
  return ;
}

void				Kitchen::nb_cook_free()
{
  std::stringstream		cook;

  cook << _nb_cook;
  if (write(_fd_in, cook.str().c_str(), cook.str().size()) <= 0)
    return ;
  usleep(100000);
  return ;
}

void				Kitchen::recup_name()
{
  if (write(_fd_in, _name.c_str(), _name.size()) <= 0)
    return ;
  usleep(100000);
  return ;
}

void				Kitchen::recup_food()
{
  std::stringstream		ress;
  std::vector<int>		tmp;

  tmp = _ressources.getRes();
  for (int i = 0; i <= 8; i++)
    ress << tmp[i];
  if (write(_fd_in, ress.str().c_str(), ress.str().size()) <= 0)
    return ;
  usleep(100000);
  return ;
}

void				Kitchen::recup_end()
{
  int				end;

  for (std::vector<Pizza>::iterator it = _pizza.begin() ; it != _pizza.end(); ++it)
    {
      end = 0;
      for (int j = 0; j <= 8; j++)
	{
	  if ((*it).getNeeded()[j] == 1 && _nb_cook > 0 && _ressources.getRes()[j] > 0)
	    end++;
	}
      if (end == 0)
	{
	  std::cout << "Pizza Ready";
	  _pizza.erase(it);
	}
    }
  return ;
}

void				Kitchen::addCuisto(int nb)
{
  _nb_cook += nb;
  return ;
}

void				Kitchen::delRessources(int id)
{
  _ressources.delRessources(id);
}

std::vector<Pizza>		Kitchen::getPizza()
{
  return (_pizza);
}
