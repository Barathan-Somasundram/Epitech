//
// resto.cpp for  in /home/somasu_b/rendu/cpp_plazza/sources/Core
//
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
//
// Started on  Tue Apr  7 12:46:04 2015 SOMASUNDRAM Barathan
// Last update Tue Apr  7 12:46:05 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <sstream>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "plazza.hpp"
#include "resto.hpp"

SFML			*Plazza::getSfml()
{
  return (_sfml);
}

int			Plazza::createKitchen()
{
  std::stringstream	name_file;
  pid_t			pid;
  struct stat		st;
  int			fd;

  name_file << "/tmp/kitchen" << _fd_in_kitchens.size();
  std::cout << "FILE CREATE => " << name_file.str() << std::endl;
  if (stat(name_file.str().c_str(), &st) != 0)
    {
      if (mkfifo(name_file.str().c_str(), S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH) == -1)
	{
	  perror ("mkfifo - the following error occurred");
	  return (-1);
	}
    }
  if ((pid = fork()) == -1)
    return (-1);
  // id = _sfml->createKitchen();
  if (pid != 0)
    {
      fd = open(name_file.str().c_str(), O_RDONLY);
      _fd_out_kitchens.push_back(fd);
      fd = open(name_file.str().c_str(), O_WRONLY);
      _fd_in_kitchens.push_back(fd);
      usleep(100000);
      return (0);
    }
  enterKitchen(name_file.str(), _fd_in_kitchens.size());
  // _sfml->destroyKitchen(id);
  return (0);
}

void			Plazza::enterKitchen(std::string name_file, int id_kitchen)
{
  Kitchen		new_kitchen(id_kitchen, name_file, _cook, _time, _mult);

  new_kitchen.recup_order();
  return ;
}

int			Plazza::recup_nb_cook(int id)
{
  std::stringstream	ss;
  char			buffer[42];
  int			size;
  int			val;

  if (write(_fd_in_kitchens[id], "free", 4) <= 0)
    return (0);
  usleep(100000);
  if ((size = read(_fd_out_kitchens[id], buffer, 41)) <= 0)
    return (0);
  buffer[size] = 0;
  ss << buffer;
  ss >> val;
  return (val);
}

std::string		Plazza::recup_name(int id)
{
  std::stringstream	ss;
  char			buffer[512];
  int			size;

  if (write(_fd_in_kitchens[id], "name", 4) <= 0)
    return ("error");
  usleep(100000);
  if ((size = read(_fd_out_kitchens[id], buffer, 511)) <= 0)
    return (0);
  buffer[size] = 0;
  ss << buffer;
  return (ss.str());
}

void		Plazza::recup_ressources(int id)
{
  if (write(_fd_in_kitchens[id], "ingredient", 10) <= 0)
    return ;
}

void			Plazza::recup_finish(int id)
{
  if (write(_fd_in_kitchens[id], "finish", 6) <= 0)
    return ;
}

void			Plazza::applyCommand(std::string commande)
{
  for (int i = 0; i < (int)_fd_in_kitchens.size(); i++)
    {
      if (write(_fd_in_kitchens[i], commande.c_str(), strlen(commande.c_str())) <= 0)
	return ;
    }
  return ;
}

