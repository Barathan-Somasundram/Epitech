/*
** Toy.h for  in /home/somasu_b/rendu/piscine_cpp_d13/ex00
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Mon Jan 19 09:48:59 2015 SOMASUNDRAM Barathan
** Last update Mon Jan 19 12:58:04 2015 SOMASUNDRAM Barathan
*/

#ifndef TOY_H_
# define TOY_H_

#include <iostream>
#include <string>
#include "Picture.h"

class				Toy
{
 public:
  typedef enum
  {
    BASIC_TOY,
    ALIEN,
    BUZZ,
    WOODY
  }	ToyType;
  
 protected:
  std::string			_Name;
  Picture			_Picture;
  ToyType			_Type;

 public:
  Toy();
  Toy(const Toy&);
  Toy(const ToyType type, const std::string name, const std::string filename);
  ~Toy();

  Toy&				operator=(const Toy&);

  ToyType			getType() const;
  std::string			getName() const;
  std::string			getAscii() const;

  void				setName(std::string name);
  bool				setAscii(std::string filename);

  virtual void			speak(const std::string);
};

#endif /* !TOY_H_ */
