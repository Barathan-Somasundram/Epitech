//
// main.cpp for  in /home/somasu_b/rendu/piscine_cpp_d13/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Mon Jan 19 10:00:57 2015 SOMASUNDRAM Barathan
// Last update Mon Jan 19 11:12:07 2015 SOMASUNDRAM Barathan
//

#include "Toy.h"

int		main()
{
  Toy toto;
  Toy ET(Toy::ALIEN, "green", "./alien.txt");

  toto.setName("TOTO !");

  if (toto.getType() == Toy::BASIC_TOY)
  std::cout << "basic toy: " << toto.getName() << std::endl
	    << toto.getAscii() << std::endl;
  if (ET.getType() == Toy::ALIEN)
  std::cout << "this alien is: " << ET.getName() << std::endl
  << ET.getAscii() << std::endl;
  return 1337;
}
