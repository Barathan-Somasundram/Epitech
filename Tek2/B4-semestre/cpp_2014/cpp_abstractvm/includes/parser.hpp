//
// parser.hpp for  in /home/somasu_b/rendu/cpp_abstractvm/includes
// 
// Made by SOMASUNDRAM Barathan
// Login   <somasu_b@epitech.net>
// 
// Started on  Tue Feb 17 17:27:53 2015 SOMASUNDRAM Barathan
// Last update Sun Mar  1 21:21:12 2015 SOMASUNDRAM Barathan
//

#ifndef PARSER_HPP_
# define PARSER_HPP_

/*
** INCLUDES 
*/
# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include "operand.hpp"

/*
** STRUCTURE
*/
typedef struct	s_lines
{
  int		_cmd;
  std::string	_value;
  eOperandType	_type;
}		t_lines;

/*
** CLASS
*/
class			Parser
{
private:
  std::string		_filename;
  int		        _cin;
  std::fstream		_file;

  int			_nb_line;
  std::string		_line;
  std::string		_ope;

  int			_cmd;
  eOperandType		_type;
  std::string		_value;

  std::vector<t_lines>	_full;
  std::vector<IOperand*>_pile;

  int			is_empty_str(void);
  int			set_line(void);
  unsigned int		line_analyse(int, int, std::string);
  int			set_cmd(void);
  int			set_ope(void);
  int			set_value(void);
  void			stock(void);
  int			exec(void);

public:
  Parser(char *file);
  ~Parser();
  
  int			file_good(void);
  int			parsing(void);
};

#endif /* !PARSER_HPP_ */
