//
// Sorcerer.hh for  in /home/somasu_b/rendu/piscine_cpp_d10/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 01:03:27 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 01:37:17 2015 SOMASUNDRAM Barathan
//

#ifndef SORCERER_HH_
# define SORCERER_HH_

#include <iostream>
#include <string>
#include "Victim.hh"

class				Victim;

class				Sorcerer
{
protected:
  std::string			name;
  std::string			title;

public:
  Sorcerer(std::string name, std::string title);
  ~Sorcerer();

  std::string			getName() const;
  std::string			getTitle() const;
  virtual void			polymorph(Victim const&) const;
};

std::ostream&			operator<<(std::ostream& w_exit, Sorcerer& sorcerer);

#endif /* !SORCERER_HH_ */
