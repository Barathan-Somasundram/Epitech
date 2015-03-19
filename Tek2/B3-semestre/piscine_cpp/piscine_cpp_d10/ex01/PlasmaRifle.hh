//
// PlasmaRifle.hh for  in /home/somasu_b/rendu/piscine_cpp_d10/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 02:25:54 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 02:28:37 2015 SOMASUNDRAM Barathan
//

#ifndef PLASMARIFLE_HH_
# define PLASMARIFLE_HH_

#include <iostream>
#include <string>
#include "AWeapon.hh"

class				PlasmaRifle : public AWeapon
{
public:
  PlasmaRifle();
  ~PlasmaRifle();

  virtual void			attack() const;
};

#endif /* !PLASMARIFLE_HH_ */
