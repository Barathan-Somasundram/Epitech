//
// Teddy.hh for  in /home/somasu_b/rendu/Rush2
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 09:38:09 2015 SOMASUNDRAM Barathan
// Last update Sun Jan 18 00:48:26 2015 XU Alexandre
//

#ifndef TEDDY_HH_
# define TEDDY_HH_

#include <iostream>
#include <string>
#include "Toy.hh"

class				Teddy : public Toy
{
public:
  Teddy(std::string name);
  Teddy(Teddy const&);
  ~Teddy();

  void				operator=(Teddy const&);
  void				isTaken();
};

std::ostream&			operator<<(std::ostream &, Teddy const &);

#endif /* !TEDDY_HH_ */
