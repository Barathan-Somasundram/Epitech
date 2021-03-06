/*
** Picture.h for  in /home/somasu_b/rendu/piscine_cpp_d13/ex00
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Mon Jan 19 09:49:13 2015 SOMASUNDRAM Barathan
** Last update Mon Jan 19 11:20:04 2015 SOMASUNDRAM Barathan
*/

#ifndef PICTURE_H_
# define PICTURE_H_

#include <iostream>
#include <string>
#include <fstream>

class				Picture
{
 public:
  std::string			data;

  Picture();
  Picture(const std::string& file);
  Picture(const Picture&);
  ~Picture();

  void				operator=(const Picture& other);
  bool				getPictureFromFile(const std::string& file);
  
};

#endif /* !PICTURE_H_ */
