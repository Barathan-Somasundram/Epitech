//
// Toy.hh for  in /home/somasu_b/rendu/Rush2
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 09:37:54 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 20:54:45 2015 Stuart Sulaski
//

#ifndef TOY_HH_
# define TOY_HH_

#include <iostream>
#include <string>
#include "Object.hh"

class				Toy : public Object
{
public:
  Toy(std::string name = "");
  Toy(Toy const&);
  virtual ~Toy();

  void				operator=(Toy const&);
};

#endif /* !TOY_HH_ */
