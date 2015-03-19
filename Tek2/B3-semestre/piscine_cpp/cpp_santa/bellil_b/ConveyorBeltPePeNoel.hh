//
// ConveyorBeltPePeNoel.hh for  in /home/xu_b/rendu/cpp_santa/xu_b
// 
// Made by XU Alexandre
// Login   <xu_b@epitech.net>
// 
// Started on  Sat Jan 17 18:25:44 2015 XU Alexandre
// Last update Sat Jan 17 18:32:00 2015 XU Alexandre
//

#ifndef __CONVEYORBELTPEPENOEL_HH__
# define __CONVEYORBELTPEPENOEL_HH__

# include "IConveyorBelt.hh"

class ConveyorBeltPePeNoel : public IConveyorBelt
{
public:
  ConveyorBeltPePeNoel();
  ~ConveyorBeltPePeNoel();
  ConveyorBeltPePeNoel(const ConveyorBeltPePeNoel &);
  void operator=(const ConveyorBeltPePeNoel &);
};

#endif /* !__CONVEYORBELTPEPENOEL_HH__ */
