/*
** sickkoala.h for  in /home/somasu_b/rendu/piscine_cpp_d06/ex02
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Mon Jan 12 11:07:12 2015 SOMASUNDRAM Barathan
** Last update Tue Jan 13 02:36:45 2015 SOMASUNDRAM Barathan
*/

#ifndef SICKKOALA_H_
# define SICKKOALA_H_

#include <iostream>
#include <string>

class			SickKoala
{
 private:
  std::string	       	name;

 public:
  SickKoala(std::string);
  ~SickKoala();
  void	       		poke();
  bool			takeDrug(std::string str);
  void			overDrive(std::string str);
  std::string		getName();
};


#endif /* !SICKKOALA_H_ */
