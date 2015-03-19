//
// cmd_fct.cpp for  in /home/somasu_b/rendu/cpp_abstractvm/sources
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Tue Feb 17 18:18:42 2015 SOMASUNDRAM Barathan
// Last update Sun Mar  1 23:04:39 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "../includes/parser.hpp"
#include "../includes/cmd_fct.hpp"
#include "../includes/my_exception.hpp"

std::string		fct_push(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename)
{
  IOperand      *op;

  filename = filename;
  op = AOperand::createOperand(type, value);
  _pile->push_back(op);
  return ("0");
}

std::string		fct_pop(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename)
{
  IOperand*		ret;

  type = type;
  value = value;
  if (_pile->size() == 0)
    {
      throw (my_exception(filename, -1, ": empty Operand", OTHER));
      return ("ERROR");
    }
  ret = _pile->back();
  _pile->pop_back();
  return (ret->toString());
}

std::string		fct_dump(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename)
{
  std::vector<IOperand *>::iterator iter;

  filename = filename;
  type = type;
  value = value;
  if (_pile->size() == 0)
    return ("");
  for (iter = _pile->end() - 1; iter != _pile->begin(); iter--)
    std::cout << (*iter)->toString() << std::endl;
  std::cout << (*iter)->toString() << std::endl;
  return ("");
}

std::string		fct_assert(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename)
{
  type = type;
  if (_pile->size() == 0 || _pile->back()->toString() != value || _pile->back()->getType() != type)
    {
      throw (my_exception(filename, -1, ": The parameter isn't equals to the top of Operand", OTHER));
      return ("ERROR");
    }
  return ("");
}

std::string		fct_add(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename)
{
  IOperand    *param1;
  IOperand    *param2;

  type = type;
  value = value;
  if (_pile->size() < 2)
    {
      throw (my_exception(filename, -1, ": Operand for Add must be taller or equal than 2", OTHER));
      return "ERROR";
    }
  param1 = _pile->back();
  _pile->pop_back();
  param2 = _pile->back();
  _pile->pop_back();
  _pile->push_back(param1->operator+(*param2));
  return ("");
}

std::string		fct_sub(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename)
{
  IOperand    *param1;
  IOperand    *param2;

  type = type;
  value = value;
  if (_pile->size() < 2)
  {
    throw (my_exception(filename, -1, ": Operand for Sub must be taller or equal than 2", OTHER));
    return "ERROR";
  }
  param1 = _pile->back();
  _pile->pop_back();
  param2 = _pile->back();
  _pile->pop_back();
  _pile->push_back(param1->operator-(*param2));
  return ("");
}

std::string		fct_div(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename)
{
  IOperand    *param1;
  IOperand    *param2;

  type = type;
  value = value;
  if (_pile->size() < 2)
    {
      throw (my_exception(filename, -1, ": Operand for Div must be taller or equal than 2", OTHER));
      return "ERROR";
    }
  param1 = _pile->back();
  _pile->pop_back();
  param2 = _pile->back();
  _pile->pop_back();
  _pile->push_back(param1->operator/(*param2));
  return ("");
}

std::string		fct_mul(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename)
{
  IOperand    *param1;
  IOperand    *param2;

  type = type;
  value = value;
  if (_pile->size() < 2)
  {
    throw (my_exception(filename, -1, ": Operand for Mul must be taller or equal than 2", OTHER));
    return "ERROR";
  }
  param1 = _pile->back();
  _pile->pop_back();
  param2 = _pile->back();
  _pile->pop_back();
  _pile->push_back(param1->operator*(*param2));
  return ("");
}

std::string		fct_mod(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename)
{
  IOperand    *param1;
  IOperand    *param2;

  type = type;
  value = value;
  if (_pile->size() < 2)
  {
    throw (my_exception(filename, -1, ": Operand for Mul must be taller or equal than 2", OTHER));
    return "ERROR";
  }
  param1 = _pile->back();
  _pile->pop_back();
  param2 = _pile->back();
  _pile->pop_back();
  _pile->push_back(param1->operator%(*param2));
  return ("");
}

std::string		fct_print(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename)
{
  int			val;
  std::stringstream	ss;

  type = type;
  value = value;
  if (_pile->size() == 0|| _pile->back()->getType() != Int8)
    {
      throw (my_exception(filename, -1, ": The type of top of Operand isn't equals to Int8", OTHER));
      return ("ERROR");
    }
  ss.str(_pile->back()->toString());
  ss >> val;
  std::cout << val << std::endl;
  std::cout << static_cast<char>(val) << std::endl;
  return ("");
}

std::string		fct_exit(std::vector<IOperand*> *_pile, eOperandType type, std::string value, std::string filename)
{
  type = type;
  value = value;
  _pile = _pile;
  filename = filename;
  std::cout << "\x1B[35m" << filename << "\x1B[36m" << ": End of Program" << "\x1B[0m" << std::endl;
  return ("EXIT");
}
