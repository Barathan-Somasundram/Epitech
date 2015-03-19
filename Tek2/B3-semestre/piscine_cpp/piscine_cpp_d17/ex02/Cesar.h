/*
** Cesar.h for  in /home/somasu_b/rendu/piscine_cpp_d17/ex02
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Sat Jan 24 00:26:36 2015 SOMASUNDRAM Barathan
** Last update Sat Jan 24 01:03:19 2015 SOMASUNDRAM Barathan
*/

#ifndef CESAR_H_
# define CESAR_H_

#include <iostream>
#include "IEncryptionMethod.h"

class Cesar : public IEncryptionMethod 
{
  int decallage;

 public:
  Cesar();
  virtual ~Cesar();

  virtual void encryptChar(char plainchar);
  virtual void decryptChar(char cipherchar);
  virtual void reset();
};

#endif /* !CESAR_H_ */
