/*
** ToyStory.h for  in /home/somasu_b/rendu/piscine_cpp_d13/ex06
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Mon Jan 19 21:58:38 2015 SOMASUNDRAM Barathan
** Last update Tue Jan 20 00:37:23 2015 SOMASUNDRAM Barathan
*/

#ifndef TOYSTORY_H_
# define TOYSTORY_H_

#include "Toy.h"

class				ToyStory
{

 public:
  ToyStory();
  ~ToyStory();

  static bool				tellMeAStory(const std::string& filename,
					     Toy&, bool (Toy::*func1)(std::string const statemt),
					     Toy&, bool (Toy::*func2)(std::string const statemt));
};

#endif /* !TOYSTORY_H_ */
