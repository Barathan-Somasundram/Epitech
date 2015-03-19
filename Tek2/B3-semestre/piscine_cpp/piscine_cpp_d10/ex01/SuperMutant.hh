//
// SuperMutant.hh for  in /home/somasu_b/rendu/piscine_cpp_d10/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 02:34:40 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 02:37:17 2015 SOMASUNDRAM Barathan
//

#ifndef SUPERMUTANT_HH_
# define SUPERMUTANT_HH_

#include <iostream>
#include <string>
#include "AEnemy.hh"

class				SuperMutant : public AEnemy
{
public:
  SuperMutant();
  ~SuperMutant();

  void				takeDamage(int damage);
};

#endif /* !SUPERMUTANT_HH_ */
