/*
** Parser.h for  in /home/somasu_b/rendu/piscine_cpp_d16/ex00
** 
** Made by SOMASUNDRAM Barathan
** Login   <somasu_b@epitech.net>
** 
** Started on  Fri Jan 23 05:27:06 2015 SOMASUNDRAM Barathan
** Last update Fri Jan 23 05:38:01 2015 SOMASUNDRAM Barathan
*/

#ifndef PARSER_H_
# define PARSER_H_

#include <iostream>
#include <string>

class				Parser
{
  int				res;
  std::stack<std::string>	op;
  std::stack<std::string>	nbs;

 public:
  Parser();
  Parser(const Parser&);
  ~Parser();

  void feed(const std::string&);
  int result() const;
  void reset();
};

#endif /* !PARSER_H_ */
