#ifndef GIFTPAPER_HH_
#define GIFTPAPER_HH_

#include <iostream>
#include <string>
#include <cstdlib>
#include "Object.hh"
#include "Wrap.hh"

class		GiftPaper: public Wrap
{
public:
  GiftPaper();
  GiftPaper(GiftPaper const &);
  void	operator=(GiftPaper const &);
  ~GiftPaper();
};

#endif /* !GIFTPAPER_HH_ */
