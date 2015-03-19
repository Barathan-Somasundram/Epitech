#ifndef WRAP_HH_
#define WRAP_HH_

#include <iostream>
#include <string>
#include <cstdlib>
#include "Object.hh"

class		Wrap: public Object
{
protected:
  bool		_isOpen;
  bool		_isEmpty;

public:
  Wrap();
  Wrap(Wrap &);
  void	operator=(Wrap const &);
  virtual ~Wrap();
  bool		isOpen();
  bool		isEmpty();
  void		openMe();
  void		closeMe();
  void		fillMe();
  void		emptyMe();
  
  Object*	wrapMeThat(Object const * &, Object const * &, Object const * &);
};

#endif /* !WRAP_HH_ */
