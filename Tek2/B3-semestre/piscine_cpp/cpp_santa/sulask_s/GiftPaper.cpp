//
// GiftPaper.cpp for cpp_santa in /home/sulask_s/rendu/cpp_santa/sulask_s
// 
// Made by Stuart Sulaski
// Login   <sulask_s@epitech.net>
// 
// Started on  Sat Jan 17 16:41:16 2015 Stuart Sulaski
// Last update Sat Jan 17 20:59:44 2015 Stuart Sulaski
//

#include "Object.hh"
#include "Wrap.hh"
#include "GiftPaper.hh"

GiftPaper::GiftPaper()
  : Wrap()
{
  name = "";
  type = NOTKNOWN;
  isTake = false;
  _isOpen = true;
  _isEmpty = true;
}

GiftPaper::GiftPaper(GiftPaper const & w)
  : Wrap()
{
  name = w.getName();
  type = w.getType();
  isTake = w.getIsTaken();
  _isOpen = isOpen();
  _isEmpty = isEmpty();
}

void	GiftPaper::operator=(GiftPaper const & w)
{
  name = w.getName();
  type = w.getType();
  isTake = w.getIsTaken();
  _isOpen = isOpen();
  _isEmpty = isEmpty();
}

GiftPaper::~GiftPaper()
{
}
