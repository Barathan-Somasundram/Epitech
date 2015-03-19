/*
** Buzz.h for  in /home/somasu_b/rendu/piscine_cpp_d13/ex02
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Mon Jan 19 11:35:32 2015 SOMASUNDRAM Barathan
** Last update Mon Jan 19 11:52:25 2015 SOMASUNDRAM Barathan
*/

#ifndef BUZZ_H_
# define BUZZ_H_

#include "Toy.h"

class				Buzz : public Toy
{
 public:
  Buzz(const std::string, const std::string filename = "buzz.txt");
  ~Buzz();
};

#endif /* !BUZZ_H_ */
