//
// ElfOfPePeNoel.hh for IElf in /home/xu_b/rendu/cpp_santa/xu_b
// 
// Made by XU Alexandre
// Login   <xu_b@epitech.net>
// 
// Started on  Sat Jan 17 15:24:32 2015 XU Alexandre
// Last update Sat Jan 17 21:02:16 2015 XU Alexandre
//

#ifndef __ELFOFPEPENOEL_HH__
# define __ELFOFPEPENOEL_HH__

# include "IElf.hh"

class	ElfOfPePeNoel : public IElf
{
  
public:
  ElfOfPePeNoel();
  ElfOfPePeNoel(const ElfOfPePeNoel&);
  ~ElfOfPePeNoel();
  void	operateur=(const ElfOfPePeNoel&);
  void wraps(Wrap::wrapMeThat(Object* &, Object* &, Object *&));
  void open(Wrap::openMe());
  void close(Wrap::closeMe());
  void PutOnTable(TablePePeNoel::putontable());
  void TakeOnTable(TablePePeNoel::takeontable());
  void LookOnTable(TablePePeNoel::lookontable());
  void PutOnConvey(ConveyorBeltPePeNoel::putonconvey());
  void TakeOnConvey(ConveyorBeltPePeNoel::takeonconvey());
  void LookOnConvey(ConveyorBeltPePeNoel::lookonconvey());
};

#endif /* !__ELFOFPEPENOEL_HH__ */
