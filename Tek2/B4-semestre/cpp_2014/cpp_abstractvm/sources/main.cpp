//
// main.cpp for  in /home/somasu_b/rendu/cpp_abstractvm/sources
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Tue Feb 17 18:43:34 2015 SOMASUNDRAM Barathan
// Last update Sun Mar  1 17:24:28 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>	
#include "../includes/parser.hpp"
#include "../includes/my_exception.hpp"

int		asm_files(char *filename)
{
  std::fstream	file;

  Parser parse(filename);
  if (strcmp(&filename[strlen(filename) - 4], ".avm") == 0)
    {
      if (parse.file_good())
	parse.parsing();
      else
	throw (my_exception(std::string(filename), -1, "", NO_FILE));
    }
  else
    throw (my_exception(filename, -1, "", BAD_EXTENSION));
  return (0);
}

int		asm_input(void)
{
  Parser parse(NULL);

  if (parse.parsing() == 2)
    return (1);
  return (0);
}

int		main(int ac, char **av)
{
  int		i = 0;

  if (ac > 1)
    {
      while (++i < ac)
	{
	  try
	    {
	      if (asm_files(av[i]) != 0)
		return (1);
	    } catch (const my_exception& error)
	    {
	      std::cerr << error.what() << std::endl;
	    }
	}
    }
  else
    {
      try
	{
	  if (asm_input() != 0)
	    return (1);
	} catch (const my_exception& error)
	{
	  std::cerr << error.what();
	}
    }
  return (0);
}
