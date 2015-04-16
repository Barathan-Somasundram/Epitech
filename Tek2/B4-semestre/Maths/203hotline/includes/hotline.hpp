
#ifndef HOTLINE_HPP
# define HOTLINE_HPP

#include <gmpxx.h>

class			Hotline
{
private:
  int                   param1;
  int                   param2;
public:
  Hotline();
  ~Hotline();
  int setParam(int, int);
  int getCombi();
  int getBin();
  int getPoisson();
};

#endif
