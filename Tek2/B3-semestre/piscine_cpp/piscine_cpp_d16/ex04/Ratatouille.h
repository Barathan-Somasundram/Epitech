/*
** Ratatouille.h for  in /home/somasu_b/rendu/piscine_cpp_d16/ex04
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Fri Jan 23 05:45:17 2015 SOMASUNDRAM Barathan
** Last update Fri Jan 23 05:52:32 2015 SOMASUNDRAM Barathan
*/

#ifndef RATATOUILLE_H_
# define  RATATOUILLE_H_

#include <iostream>
#include <string>
#include <sstream>

class				Ratatouille 
{
 protected:
  std::stringstream		_str;

 public:
  Ratatouille();
  Ratatouille(const Ratatouille&);
  ~Ratatouille();

  Ratatouille&			operator=(const Ratatouille&);

  Ratatouille&			addVegetable(unsigned char);
  Ratatouille&			addCondiment(unsigned int);
  Ratatouille&			addSpice(double);
  Ratatouille&			addSauce(std::string);
  std::string			kooc();
};

#endif /* ! RATATOUILLE_H_ */
