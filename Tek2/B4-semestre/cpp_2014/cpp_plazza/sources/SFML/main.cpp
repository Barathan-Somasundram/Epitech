//
// main.cpp for  in /home/llyth/rendu/cpp_plazza/sources/SFML
//
// Made by llyth
// Login   <llyth@epitech.net>
//
// Started on  Sun Apr 26 11:24:32 2015 llyth
// Last update Sun Apr 26 18:01:07 2015 llyth
//

#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include "SFML.hpp"

int	main()
{
  SFML	Test(666);
  int	id;

  for (int i = 0; i < 9; ++i)
    id = Test.createKitchen();
  Test.setWorkingCook(8, 333);
  Test.destroyKitchen(3);
  Test.destroyKitchen(8);
  std::cout << Test.createKitchen() << std::endl;
  std::cout << Test.createKitchen() << std::endl;
  Test.setWorkingCook(8, 1);
  Test.destroyKitchen(3);
  Test.setWorkingCook(8, 666);
  Test.setWorkingCook(3, 333);
  while (Test.isOpen())
    {
      Test.displayArea();
      Test.closeWinEvent();
      usleep(10000);
    }
  return (0);
}
