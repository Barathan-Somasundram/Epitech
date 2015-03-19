//
// TablePePeNoel.hh for $= in /home/xu_b/rendu/cpp_santa/xu_b
// 
// Made by XU Alexandre
// Login   <xu_b@epitech.net>
// 
// Started on  Sat Jan 17 18:25:26 2015 XU Alexandre
// Last update Sat Jan 17 20:27:26 2015 Bellili Ayoub
//

#ifndef__TABLEPEPENOEL_HH__
# define __TABLEPEPENOEL_HH__

# include "ITable.hh"

class	TablePePeNoel : public ITable
{
public:
  TablePePeNoel();
  ~TablePePeNoel();
  TablePePeNoel(const TablePePeNoel &);
  void operator=(const TablePePeNoel &);
};

#endif /* !__TABLEPEPENOEL_HH__ */
