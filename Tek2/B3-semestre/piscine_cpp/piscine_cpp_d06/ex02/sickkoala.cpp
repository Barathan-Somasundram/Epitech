//
// sickkoala.cpp for  in /home/somasu_b/rendu/piscine_cpp_d06/ex02
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Mon Jan 12 11:08:11 2015 SOMASUNDRAM Barathan
// Last update Tue Jan 13 03:32:46 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include "sickkoala.h"

SickKoala::SickKoala(std::string name)
{
  this->name = name;
}

SickKoala::~SickKoala()
{
  std::cout << "Mr." << this->name << ": Kreooogg !! Je suis gueriiii !" << std::endl;
}

void		SickKoala::poke()
{
  std::cout << "Mr." << this->name << ": Gooeeeeerrk !! :'(" << std::endl;
}

bool		SickKoala::takeDrug(std::string str)
{
  if (std::tolower(str[0]) == 'm' && std::tolower(str[1]) == 'a'
      && std::tolower(str[2]) == 'r' && std::tolower(str[3]) == 's')
    {
      std::cout << "Mr." << this->name << ": Mars, et ca kreog !" << std::endl;
      return (true);
    }
  else if (str == "Buronzand")
    {
      std::cout << "Mr." << this->name << ": Et la fatigue a fait son temps !" << std::endl;
      return (true);
    }
  else
    {
      std::cout << "Mr." << this->name << ": Goerkreog !" << std::endl;
      return (false);
    }
  return (false);
}

void		SickKoala::overDrive(std::string str)
{
  int		pos;

  while ((pos = str.find("Kreog !")) != std::string::npos)
    str.replace(pos, 7, "1337 !");
  std::cout << "Mr." << this->name << ": " << str << std::endl;
}
