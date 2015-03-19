#ifndef BOX_HH_
#define BOX_HH_

#include <iostream>
#include <string>
#include <cstdlib>
#include "Object.hh"
#include "Wrap.hh"

class		Box: public Wrap
{
public:
  Box();
  Box(Box const &);
  void	operator=(Box const &);
  ~Box();
};

#endif /* !BOX_HH */
