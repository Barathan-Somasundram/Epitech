//
// Peon.hh for  in /home/somasu_b/rendu/piscine_cpp_d10/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 00:45:24 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 17 00:47:34 2015 SOMASUNDRAM Barathan
//

#ifndef PEON_H_
# define PEON_H_

#include "Victim.hh"

class				Peon : public Victim
{
public:
  Peon(std::string name);
  ~Peon();

  void				getPolymorphed() const;
};

#endif /* !PEON_H_ */
