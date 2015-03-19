//
// OneTime.cpp for  in /home/somasu_b/rendu/piscine_cpp_d17/ex02
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Sat Jan 24 07:49:17 2015 SOMASUNDRAM Barathan
// Last update Sat Jan 24 07:58:44 2015 SOMASUNDRAM Barathan
//

#include "OneTime.h"

OneTime::OneTime(std::string key) 
{
  _key = key;
  _idx = 0;
}

OneTime::~OneTime() 
{

}

void				OneTime::reset() 
{
  _idx = 0;
}

void				OneTime::encryptChar(char plainchar) 
{
  int				b;
  int				kb;

  b = plainchar >= 'a' ? 'a' : 'A';
  kb = _key[_idx] >= 'a' ? 'a' : 'A';
  if (isalpha(plainchar)) 
    plainchar = (plainchar - b + (_key[_idx] - kb)) % 26 + b;
  std::cout << plainchar;
  _idx = (_idx + 1) % _key.size();
}

void				OneTime::decryptChar(char cipherchar) 
{
  int				b;
  int				kb;

  b = cipherchar >= 'a' ? 'z' : 'Z';
  kb = _key[_idx] >= 'a' ? 'a' : 'A';
  if (isalpha(cipherchar)) 
    cipherchar = (cipherchar - b - (_key[_idx] - kb)) % 26 + b;
  std::cout << cipherchar;
  _idx = (_idx + 1) % _key.size();
}
