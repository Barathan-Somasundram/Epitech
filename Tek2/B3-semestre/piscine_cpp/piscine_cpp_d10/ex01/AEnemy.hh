//
// AEnemy.hh for  in /home/somasu_b/rendu/piscine_cpp_d10/ex01
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 01:57:57 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 09:04:31 2015 SOMASUNDRAM Barathan
//

#ifndef AENEMY_H_
# define AENEMY_H_

#include <iostream>
#include <string>

class				AEnemy
{
protected:
  std::string			type;
  int				hp;

public:
  AEnemy(int hp, std::string const& type);
  virtual ~AEnemy();

  std::string const&		getType() const;
  int				getHP() const;
  virtual void			takeDamage(int damage);
};

#endif /* !AENEMY_H_ */
