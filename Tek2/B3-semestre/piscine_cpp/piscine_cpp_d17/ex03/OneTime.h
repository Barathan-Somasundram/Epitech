/*
** OneTime.h for  in /home/somasu_b/rendu/piscine_cpp_d17/ex02
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sat Jan 24 07:46:41 2015 SOMASUNDRAM Barathan
** Last update Sat Jan 24 07:48:39 2015 SOMASUNDRAM Barathan
*/

#ifndef ONETIME_H_
# define ONETIME_H_

#include <iostream>
#include <string>
#include "IEncryptionMethod.h"

class				OneTime : public IEncryptionMethod 
{
  std::string			_key;
  int				_idx;

 public:
  OneTime(std::string key);
  virtual ~OneTime();

  virtual void			encryptChar(char plainchar);
  virtual void			decryptChar(char cipherchar);
  virtual void			reset();
};


#endif /* !ONETIME_H_ */
