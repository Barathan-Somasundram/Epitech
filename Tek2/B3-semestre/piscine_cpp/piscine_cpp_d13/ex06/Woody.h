/*
** Woody.h for  in /home/somasu_b/rendu/piscine_cpp_d13/ex02
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Mon Jan 19 11:35:58 2015 SOMASUNDRAM Barathan
** Last update Mon Jan 19 23:11:51 2015 SOMASUNDRAM Barathan
*/

#ifndef WOODY_H_
# define WOODY_H_

#include "Toy.h"

class				Woody : public Toy
{
 public:
  Woody(const std::string, const std::string filename = "woody.txt");
  ~Woody();

  bool				speak(const std::string);
};

#endif /* !WOODY_H_ */
