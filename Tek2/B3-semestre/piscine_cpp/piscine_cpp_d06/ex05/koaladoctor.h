/*
** koaladoctor.h for  in /home/somasu_b/rendu/piscine_cpp_d06/ex04
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Mon Jan 12 17:09:49 2015 SOMASUNDRAM Barathan
** Last update Tue Jan 13 03:02:03 2015 SOMASUNDRAM Barathan
*/

#ifndef KOALADOCTOR_H_
# define KOALADOCTOR_H_

#include <iostream>
#include <string>
#include "sickkoala.h"
#include "koalanurse.h"

class			KoalaDoctor
{
 private:
  std::string		name;

 public:
  KoalaDoctor(std::string name);
  ~KoalaDoctor();
  void			diagnose(SickKoala *patient);
  void			timeCheck();
  std::string		getName();
};

#endif /* !KOALADOCTOR_H_ */
