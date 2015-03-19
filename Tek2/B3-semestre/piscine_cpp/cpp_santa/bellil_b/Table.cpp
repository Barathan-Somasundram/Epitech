//
// Table.cpp for table in /home/bellil_b/work/cpp_santa/part4
// 
// Made by Bellili Ayoub
// Login   <bellil_b@epitech.net>
// 
// Started on  Sat Jan 17 11:59:18 2015 Bellili Ayoub
// Last update Sat Jan 17 22:55:11 2015 Bellili Ayoub
//

#include "Table.hh"

Table::Table()
{
  int		a = -1;

  while (++a < 10)
    in[0][a] == NULL;
  in[1] == NULL;
}

Object	*Table::getObject() const ;
{
  return (in);
}

bool	Table::putObject(const Object& *cp_in);
{
  int	i = 0;

  while (i < 10)
    if (in[i] == NULL)
      {
	in[i] = cp_in;
	return (true);
      }
  return (false);
}
