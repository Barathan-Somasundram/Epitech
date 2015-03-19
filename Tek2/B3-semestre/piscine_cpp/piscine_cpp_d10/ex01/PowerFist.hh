//
// PowerFist.hh for  in /home/somasu_b/rendu/piscine_cpp_d10/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 02:29:37 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 02:31:25 2015 SOMASUNDRAM Barathan
//

#ifndef POWERFIST_HH_
# define POWERFIST_HH_

#include <iostream>
#include <string>

class				PowerFist : public AWeapon
{
public:
  PowerFist();
  ~PowerFist();

  virtual void			attack() const;
};

#endif /* !POWERFIST_HH_ */
