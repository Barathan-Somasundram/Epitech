//
// Toy.hh for  in /home/somasu_b/rendu/Rush2
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 09:37:54 2015 SOMASUNDRAM Barathan
// Last update Sun Jan 18 04:46:59 2015 SOMASUNDRAM Barathan
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
  virtual Object*			wrapMeThat(Object const * &, Object const * &, Object const * &);
  virtual void				openMe();
  virtual void				closeMe();
  virtual bool				isOpen();
  virtual bool				isEmpty()};
  virtual void				fillMe();
};

#endif /* !TOY_HH_ */
