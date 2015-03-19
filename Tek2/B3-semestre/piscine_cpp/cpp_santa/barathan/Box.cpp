//
// Box.cpp for cpp_santa in /home/sulask_s/rendu/cpp_santa/sulask_s
// 
// Made by Stuart Sulaski
// Login   <sulask_s@epitech.net>
// 
// Started on  Sat Jan 17 16:44:47 2015 Stuart Sulaski
// Last update Sat Jan 17 20:58:46 2015 Stuart Sulaski
//

#include "Object.hh"
#include "Wrap.hh"
#include "Box.hh"

Box::Box()
  : Wrap()
{
  name = "";
  type = NOTKNOWN;
  isTake = false;
  _isOpen = true;
  _isEmpty = true;
}

Box::Box(Box const & w)
  : Wrap()
{
  name = w.getName();
  type = w.getType();
  isTake = w.getIsTaken();
  _isOpen = isOpen();
  _isEmpty = isEmpty();
}

void	Box::operator=(Box const & w)
{
  name = w.getName();
  type = w.getType();
  isTake = w.getIsTaken();
  _isOpen = isOpen();
  _isEmpty = isEmpty();
}

Box::~Box()
{
}
