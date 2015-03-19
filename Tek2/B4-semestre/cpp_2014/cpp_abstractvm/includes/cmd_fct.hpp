//
// cmd_fct.hpp for  in /home/somasu_b/rendu/cpp_abstractvm/includes
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Tue Feb 17 18:01:16 2015 SOMASUNDRAM Barathan
// Last update Sun Mar  1 14:55:03 2015 SOMASUNDRAM Barathan
//

#ifndef CMD_FCT_HPP_
# define CMD_FCT_HPP_

/*
** INCLUDES 
*/
# include <iostream>
# include <string>
# include "operand.hpp"

/*
** STRUCTURE
*/
typedef struct	s_cmd
{
  std::string	cmd;
  std::string	(*function)(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename);
}		t_cmd;

typedef std::string	t_ope;

std::string		fct_push(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename);
std::string		fct_pop(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename);
std::string		fct_dump(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename);
std::string		fct_assert(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename);
std::string		fct_add(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename);
std::string		fct_sub(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename);
std::string		fct_div(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename);
std::string		fct_mul(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename);
std::string		fct_mod(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename);
std::string		fct_print(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename);
std::string		fct_exit(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename);

/*
** GLOBAL
*/
const static t_cmd	command[12] =
  {
    {"push", &fct_push},
    {"pop", &fct_pop},
    {"dump", &fct_dump},
    {"assert", &fct_assert},
    {"add", &fct_add},
    {"sub", &fct_sub},
    {"mul", &fct_mul},
    {"div", &fct_div},
    {"mod", &fct_mod},
    {"print", &fct_print},
    {"exit", &fct_exit},
    {"", NULL}
  };

const static t_ope	ope_type[6] = 
  {
    "int8(",
    "int16(",
    "int32(",
    "float(",
    "double(",
    ""
  };

#endif /* !CMD_FCT_HPP */
