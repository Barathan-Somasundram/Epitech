/*
** koalanurse.h for  in /home/somasu_b/rendu/piscine_cpp_d06/ex03
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Mon Jan 12 16:14:19 2015 SOMASUNDRAM Barathan
** Last update Tue Jan 13 09:46:17 2015 SOMASUNDRAM Barathan
*/

#ifndef KOALANURSE_H_
#define KOALANURSE_H_

#include <iostream>
#include <string>
#include "sickkoala.h"

class			KoalaNurse
{
 private:
  int			id;
  int			if_work;

 public:
  KoalaNurse(int id);
  ~KoalaNurse();
  void			giveDrug(std::string drug, SickKoala *patient);
  std::string		readReport(std::string filename);
  void			timeCheck();
};

#endif /* !KOALANURSE_H_ */
