//
// main.cpp for  in /home/somasu_b/rendu/cpp_plazza/sources/User
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sun Apr 26 18:19:57 2015 SOMASUNDRAM Barathan
// Last update Sun Apr 26 18:19:57 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <QApplication>
#include <QDialog>
#include <string>
#include "plazza.hpp"
#include "my_exception.hpp"

int		main(int ac, char **av)
{
  if (ac != 4)
    {
      std::cerr << "./plazza [multiplier cook time] [cook per kitchen] [supply time]" << std::endl;
      std::cerr << "Error: " << (ac > 4 ? "Too many arguments" : "Too few arguments") << std::endl;
      return (0);
    }
  try {
    QApplication	app(ac, av);
    Plazza		plazza;

    if (plazza.isDigit(av[1]) == 1)
      throw (my_exception("first paramter is wrong, must be an integer"));
    if (plazza.isDigit(av[2]) == 1)
      throw (my_exception("second paramter is wrong, must be an integer"));
    if (plazza.isDigit(av[3]) == 1)
      throw (my_exception("third paramter is wrong, must be an integer"));
    plazza.setArg(atoi(av[1]), atoi(av[2]), atoi(av[3]));
    plazza.createKitchen();
    plazza.run();
    return (app.exec());
  } catch (const my_exception& error) {
    std::cout << "Error: " << error.what() << std::endl;
  }
  return (1);
}
