//
// Parser.cpp for  in /home/somasu_b/rendu/cpp_abstractvm/sources
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Thu Feb 19 15:11:24 2015 SOMASUNDRAM Barathan
// Last update Sun Mar  1 22:56:30 2015 SOMASUNDRAM Barathan
//

#include <iostream>
#include <fstream>
#include "../includes/parser.hpp"
#include "../includes/cmd_fct.hpp"
#include "../includes/my_exception.hpp"
#include <string>

Parser::Parser(char *file)
{
  _cin = 0;
  if (file == NULL)
    {
      _cin = 1;
      _filename = std::string("standart input");
    }
  else
    {
      _file.open(file);
      _filename = std::string(file);
    }
  _line = "";
  _ope = "";
  _value = "";
  _cmd = -1;
  _type = Int8;
  _nb_line = -1;
}

Parser::~Parser()
{

}

int				Parser::file_good(void)
{
  return (_file.good());
}

int				Parser::is_empty_str(void)
{
  unsigned int			i = 0;

  if (_line == ";;" && _cin == 1)
    return (1);
  if (_line == "\0")
    return (0);
  while (i < _line.size())
    {
      if (_line.c_str()[i] != ' ' && _line.c_str()[i] != '\t' 
	  && _line.c_str()[i] != ';')
	return (1);
      if (_line.c_str()[i] == ';')
	return (0);
      ++i;
    }
  return (0);
}

int				Parser::set_line(void)
{
  int				ok = 0;

  while (ok == 0)
    {
      if (!getline((_cin == 0 ? _file : std::cin), _line, '\n'))
	return (1);
      ok = is_empty_str();
      _nb_line++;
    }
  return (0);
}

unsigned int			Parser::line_analyse(int cmd, int mod, std::string ana)
{
  const char			*str;
  unsigned int			i = 0;
  
  if (mod == 1 && (cmd == 0 || cmd == 3))
    return (0);
  str = ana.c_str();
  while (str[i] != '\0')
    {
      if (str[i] == ';')
	return (i);
      if (str[i] != ' ' && str[i] != '\t')
	return (i);
      ++i;
    }
  return (0);
}

int				Parser::set_cmd(void)
{
  unsigned int			i = 0;

  while (i < 12 && _line.find(command[i].cmd.c_str()) == std::string::npos)
    ++i;
  if (line_analyse(1, 0, _line) != _line.find(command[i].cmd.c_str()))
    throw (my_exception(_filename, _nb_line, _line, LINE_CMD));
  if (command[i].cmd.size() == 0)
    {
      throw (my_exception(_filename, _nb_line, _line, LINE_CMD));
      return (1);
    }
  if (line_analyse(i, 1, std::string(&(_line.c_str()[command[i].cmd.size()]))) != 0)
    throw (my_exception(_filename, _nb_line, _line, LINE_CMD));    
  _cmd = i;
  if (_cmd != 0 && _cmd != 3)
    _ope = "";
  return (0);
}

int				Parser::set_value(void)
{
  const char			*str;
  unsigned int			tmp, i = 0;
 
  str = _ope.c_str();
  while (i < _ope.size() && str[i] != '(')
    ++i;
  tmp = ++i;
  if (str[i] == '-')
      ++i;
  while (i < _ope.size() && str[i] != ')')
    {
      if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
	{
	  throw (my_exception(_filename, _nb_line, _line, LINE_PARAM));
	  return (1);
	}
      ++i;
    }
  _value = std::string(&(_ope.c_str()[tmp]));
  _value.resize(_value.size() - 1);
  return (0);
}

int				Parser::set_ope(void)
{
  const char			*str;
  size_t			pos = 0;
  unsigned int			i = 0;
  int				j = 0;

  _ope = std::string(&(_line.c_str()[command[_cmd].cmd.size()]));
  str = _ope.c_str();
  while (str && str[i] && (str[i] == ' ' || str[i] == '\t'))
    ++i;
  while (&str[i] && ope_type[j].size() != 0
  	 && (pos = _ope.find(ope_type[j])) == std::string::npos)
    ++j;
  if (line_analyse(1, 0, _ope) != pos)
    if (_ope.find(ope_type[j].c_str()) != std::string::npos)
      throw (my_exception(_filename, _nb_line, _line, LINE_PARAM));    
  if (ope_type[j].size() == 0)
    {
      throw (my_exception(_filename, _nb_line, _line, LINE_SYNTAX));
      return (1);
    }

  while (str && str[i] && str[i] != '(')
    ++i;
  if (str[i] != '(')
    {
      throw (my_exception(_filename, _nb_line, _line, LINE_SYNTAX));
      return (1);
    }
  while (str[i] && str[i] != ')')
    ++i;
  if (str[i] != ')' && line_analyse(_cmd, 0, std::string(&(_ope.c_str()[i + 1]))) != 0)
    {
      throw (my_exception(_filename, _nb_line, _line, LINE_SYNTAX));
      return (1);
    }
  if (line_analyse(_cmd, 0, std::string(&(_ope.c_str()[i + 1]))) != 0)
    throw (my_exception(_filename, _nb_line, _line, LINE_SYNTAX));
  _type = static_cast<eOperandType>(j);
  return (0);
}

int				Parser::exec(void)
{
  std::vector<t_lines>		tmp;
  t_lines			line;
  std::string			ret = "";

  if (_full.size() == 0)
    return (0);
  while (_full.size() != 0)
    {
      line = _full.back();
      _full.pop_back();
      tmp.push_back(line);
    }
  while (tmp.size() != 0)
    {
      line = tmp.back();
      tmp.pop_back();
      ret = command[line._cmd].function(&_pile, line._type, line._value, _filename);
      if (ret == "EXIT")
	return (1);
    }
  return (1);
}

void				Parser::stock(void)
{
  t_lines			line;

  line._cmd = _cmd;
  line._type = _type;
  line._value = _value;
  _full.push_back(line);
}

int				Parser::parsing(void)
{
  std::string			ret = "";

  while (set_line() == 0)
    {
      if (_line == ";;" && _cin == 1)
	{
	  if (exec() == 1)
	    return (1);
	}
      if (set_cmd() == 1)
      	return (1);
      if ((_cmd == 0 || _cmd == 3) && set_ope() == 1)
      	return (1);
      if (_cmd == 0 || _cmd == 3)
	if (set_value() == 1)
	  return (1);
      if (_cin != 1)
	{
	  ret = command[_cmd].function(&_pile, _type, _value, _filename);
	  if (ret == "EXIT")
	    return (0);
	}
      else
	stock();
    }
  throw (my_exception(_filename, -1, "", EXIT));
  return (1);
}
