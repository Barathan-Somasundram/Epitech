//
// Cesar.cpp for  in /home/somasu_b/rendu/piscine_cpp_d17/ex02
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 24 00:28:17 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 24 08:10:40 2015 SOMASUNDRAM Barathan
//

#include "Cesar.h"

Cesar::Cesar() 
{
  decallage = 3;
}
Cesar::~Cesar() 
{

}

void				Cesar::reset() 
{
  decallage = 3;
}

void				Cesar::encryptChar(char plainchar) 
{
  if (isalpha(plainchar)) 
    {
      if (plainchar >= 'a')
	plainchar = (plainchar - 'a' + decallage) % 26 + 'a';
      else
	plainchar = (plainchar - 'A' + decallage) % 26 + 'A';
    }
  decallage = (decallage + 1) % 26;
  std::cout << plainchar;
}

void				Cesar::decryptChar(char cipherchar) 
{
  if (isalpha(cipherchar)) 
    {
      if (cipherchar >= 'a')
	cipherchar = (cipherchar - 'z' - decallage) % 26 + 'z';
      else
	cipherchar = (cipherchar - 'Z' - decallage) % 26 + 'Z';
    }
  decallage = (decallage + 1) % 26;
  std::cout << cipherchar;
}
