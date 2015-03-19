#include "Object.hh"
#include "Wrap.hh"

Wrap::Wrap()
  : Object("")
{
  type = NOTKNOWN;
  isTake = false;
  _isOpen = true;
  _isEmpty = true;
}

Wrap::Wrap(Wrap & w)
  : Object(w.getName())
{
  type = w.getType();
  isTake = w.getIsTaken();
  _isOpen = isOpen();
  _isEmpty = isEmpty();
}

Wrap::~Wrap()
{
}


bool	Wrap::isOpen()
{
  return _isOpen;
}

bool	Wrap::isEmpty()
{
  return _isEmpty;
}

void	Wrap::openMe()
{
  _isOpen = true;
}

void	Wrap::closeMe()
{
  _isOpen = false;
}

void	Wrap::fillMe()
{
  _isEmpty = false;
}

void	Wrap::emptyMe()
{
  _isEmpty = true;
}

void	Wrap::operator=(Wrap const & w)
{
  name = w.getName();
  type = w.getType();
  isTake = w.getIsTaken();
  _isOpen = isOpen();
  _isEmpty = isEmpty();
}

Object*	Wrap::wrapMeThat(const Object *& toy, const Object * & box, const Object * & giftpaper)
{
  Object	*gift = new Object[3]; // {*toy, *box, *giftpaper, NULL}

  gift[0] = *toy;
  gift[1] = *box;
  gift[2] = *giftpaper;
  if (toy->isToy() == false || box->isWrap() == false || giftpaper->isWrap() == false)
    return NULL;
  for (int i = 0; i < 3; ++i)
    if (gift[i].isOpen() == false || gift[i].isEmpty() == false)
      return NULL;

  for (int i = 0; i < 3; ++i)
    {
      gift[i].closeMe();
      gift[i].fillMe();
    }
  return gift;
}
