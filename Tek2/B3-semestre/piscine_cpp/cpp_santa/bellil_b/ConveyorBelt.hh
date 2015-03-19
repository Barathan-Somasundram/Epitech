//
// ConveyorBelt.hh for ConveyorBelt in /home/bellil_b/work/cpp_santa/bellil_b
// 
// Made by Bellili Ayoub
// Login   <bellil_b@epitech.net>
// 
// Started on  Sat Jan 17 15:29:09 2015 Bellili Ayoub
// Last update Sat Jan 17 23:14:26 2015 Bellili Ayoub
//

#ifndef CONVEYORBELT_HH_
# define CONVEYORBELT_HH_

#include "IConveyorBelt.hh"
#include "Object.hh"

class	ConveyorBelt : IConveyorBelt
{
private:
  object	*onBelt;
public:
  Object	getObject() const ;
  void		putObject(const Object& *);
  void		inObject(const Object& *);
  void		outObject(const Object& *);
};

#endif /* CONVEYORBELT_H_ !*/
