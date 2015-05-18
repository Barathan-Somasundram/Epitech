//
// main.cpp for  in /home/somasu_b/rendu/cpp_nibbler/sources/algo
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Thu Apr  2 00:17:19 2015 SOMASUNDRAM Barathan
// Last update Sun Apr  5 23:37:13 2015 SOMASUNDRAM Barathan
//

#include <cstdlib>
#include "Nibbler.hpp"

static int     	helps(int ac)
{
  if (ac != 4)
    std::cerr << "Usage: ./nibbler [x > 10] [y > 10] [libgraphic.so]" << std::endl;
  return (1);
}

int		main(int ac, char** av)
{
  if (ac != 4)
    return (helps(ac));
  if (atoi(av[1]) < 10 || atoi(av[2]) < 10)
    return (helps(0));
  Nibbler	game(av);
  try
    {
      game.initialize();
      game.launch();
    }
  catch (std::exception &e)
    {
      std::cerr << "Error: " << e.what() << std::endl;
      return (1);
    }
  std::cout << "Score: " << game.getScore() << std::endl;
  return (0);
}
