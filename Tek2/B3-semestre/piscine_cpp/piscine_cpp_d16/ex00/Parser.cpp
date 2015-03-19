//
// Parser.cpp for  in /home/somasu_b/rendu/piscine_cpp_d16/ex00
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Fri Jan 23 05:34:45 2015 SOMASUNDRAM Barathan
// Last update Fri Jan 23 05:44:42 2015 SOMASUNDRAM Barathan
//

#include "Parser.h"

Parser::Parser()
{
  res = 0;
}

Parser::Parser(const std:string& str)
{
  res = str.res;
  op = str.op;
  nbs = str.nbs;
}

Parser::~Parser()
{

}

void				Parser::feed(const std::string& str)
{
  
}

