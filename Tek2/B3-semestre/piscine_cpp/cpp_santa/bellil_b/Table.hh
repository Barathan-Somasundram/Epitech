//
// Table.hh for table in /home/bellil_b/work/cpp_santa/part4
// 
// Made by Bellili Ayoub
// Login   <bellil_b@epitech.net>
// 
// Started on  Sat Jan 17 11:59:07 2015 Bellili Ayoub
// Last update Sat Jan 17 23:14:23 2015 Bellili Ayoub
//

#ifndef TABLE_HH_
# define TABLE_HH_

#include "ITable.hh"
#include "Object.hh"

class	Table  : ITable
{
private:
  object		in[][11];
protected:
  Object	*getObject() const ;
  bool		putObject(const Object& *);
};

#endif /* TABLE_H_ !*/
