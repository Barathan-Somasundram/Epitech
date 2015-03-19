//
// Victim.hh for  in /home/somasu_b/rendu/piscine_cpp_d10/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 00:50:54 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 01:52:14 2015 SOMASUNDRAM Barathan
//

#ifndef VICTIM_HH_
# define VICTIM_HH_

#include <iostream>
#include <string>

class				Victim
{
protected:
  std::string			name;
  
public:
  Victim(std::string name);
  ~Victim();

  virtual std::string		getName() const;
  virtual void			getPolymorphed() const;
};

std::ostream&			operator<<(std::ostream& w_exit, Victim& victim);

#endif /* !VICTIM_HH_ */
