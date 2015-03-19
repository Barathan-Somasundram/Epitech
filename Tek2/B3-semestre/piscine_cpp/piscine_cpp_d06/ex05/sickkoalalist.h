/*
** sickkoalalist.h for  in /home/somasu_b/rendu/piscine_cpp_d06/ex05
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Tue Jan 13 03:05:41 2015 SOMASUNDRAM Barathan
** Last update Tue Jan 13 03:18:45 2015 SOMASUNDRAM Barathan
*/

#ifndef 

#include <iostream>
#include <string>

class			SickKoalaList
{
 private:
  SickKoala		*one;
  SickKoalaList		*next;

 public:
  SickKoalaList(SickKoala *koala);
  ~SickKoalaList();
  bool			isEnd();
  void			append(SickKoalaList *elem);
  SickKoalaList		*remove(SickKoalaList *elem);
  SickKoalaList		*removeFromName(std::string name);
  void			dump();
  SickKoala		*getItem();
};
