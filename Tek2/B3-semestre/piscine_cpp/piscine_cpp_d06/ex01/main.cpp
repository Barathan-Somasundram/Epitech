//
// main.cpp for my_convert_temp in /home/somasu_b/rendu/piscine_cpp_d06/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Mon Jan 12 09:15:03 2015 SOMASUNDRAM Barathan
// Last update Mon Jan 12 20:02:40 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <iomanip>
#include <string>


int		main(int argc, char **argv)
{
  float		degrees;
  std::string	type;
 
  std::cin >> degrees;
  std::cin >> type;
  std::cout << std::fixed;
  if (type == "Celsius")
    {
      degrees = degrees * 9.0 / 5.0 + 32;
      std::cout << std::setw(16) << std::right << std::setprecision(3) << degrees << std::setw(16) << " Fahrenheit" << std::endl;
    }
  else if (type == "Fahrenheit")
    {
      degrees = 5.0 / 9.0 * (degrees - 32);
      std::cout << std::setw(16) << std:: right << std::setprecision(3) << degrees <<  std::setw(16) << " Celsius" << std::endl;
    }
  else
    return (1);
  return (0);
}
