//
// main.cpp for my_cat in /home/somasu_b/rendu/piscine_cpp_d06/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Mon Jan 12 09:15:03 2015 SOMASUNDRAM Barathan
// Last update Mon Jan 12 16:34:51 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <fstream>
#include <string>

int		main(int argc, char **argv)
{
  int		i = 1;
  std::fstream	file;
  std::string	line;

  if (argc < 2)
    {
      std::cout << "my_cat: Usage : ./my_cat file [...]" << std::endl;
      return (1);
    }
  while (i < argc)
    {
      file.open(argv[i]);
      if (!file.is_open())
	{
	  std::cout << "my_cat: <" << argv[i] << ">: No such file or directory" << std::endl;
	  return (1);
	}
      while (std::getline(file, line, '\0'))
	std::cout << line;
      file.close();
      ++i;
    }
  return (0);
}
