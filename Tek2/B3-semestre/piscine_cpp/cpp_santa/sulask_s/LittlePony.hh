//
// LittlePony.hh for  in /home/somasu_b/rendu/Rush2
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 17 09:38:16 2015 SOMASUNDRAM Barathan
// Last update Sun Jan 18 00:45:47 2015 XU Alexandre
//

#ifndef LITTLEPONY_HH_
# define LITTLEPONY_HH_

#include <iostream>
#include <string>
#include "Toy.hh"

class				LittlePony : public Toy
{
public:
  LittlePony(std::string name = "");
  LittlePony(LittlePony const&);
  ~LittlePony();

  void				operator=(LittlePony const&);
  void				isTaken();
};

std::ostream&			operator<<(std::ostream &, LittlePony const &);

#endif /* !LITTLEPONY_HH_ */
