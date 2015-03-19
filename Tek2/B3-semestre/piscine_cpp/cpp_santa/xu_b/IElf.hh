//
// IElf.hh for IElf in /home/xu_b/rendu/cpp_santa
// 
// Made by XU Alexandre
// Login   <xu_b@epitech.net>
// 
// Started on  Sat Jan 17 11:40:37 2015 XU Alexandre
// Last update Sat Jan 17 18:43:44 2015 XU Alexandre
//

#ifndef __IELF_HH__
# define __IELF_HH__

# include "Wrap.hh"
# include "TablePePeNoel.hh"
# include "ConveyorBeltPePeNoel.hh"

class	IElf
{
  
public:
  virtual ~IElf();
  void wraps(Wrap::wrapMeThat(Object* &, Object* &, Object *&)) const = 0;
  void open(Wrap::openMe()) const = 0;
  void close(Wrap::closeMe()) const = 0;
  void PutOnTable(TablePePeNoel::putontable()) const = 0;
  void TakeOnTable(TablePePeNoel::takeontable()) const = 0;
  void LookOnTable(TablePePeNoel::lookontable()) const = 0;
  void PutOnConvey(ConveyorBeltPePeNoel::putonconvey()) const = 0;
  void TakeOnConvey(ConveyorBeltPePeNoel::takeonconvey()) const = 0;
  void LookOnConvey(ConveyorBeltPePeNoel::lookonconvey()) const = 0;
};

#endif /* !__IELF_HH__ */
